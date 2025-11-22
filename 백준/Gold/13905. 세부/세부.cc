#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>

using namespace std;

typedef pair<int, int> PAIR;

int n, m, is, ie;

vector<vector<PAIR>> graph;

int solve(){
    priority_queue<PAIR> pq;
    vector<int> weights(n + 1, -1);
    weights[is] = INT_MAX;
    pq.push({INT_MAX, is});
    
    while(!pq.empty()){
        int s = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        
        vector<PAIR>& v = graph[s];
        for(int i=0;i<v.size();i++){
            int e = v[i].first;
            int nextWeight = min(v[i].second, weight);
            
            if(weights[e] == -1 || weights[e] < nextWeight){
                pq.push({nextWeight, e});
                weights[e] = nextWeight;
            }
        }
    }
    
    return weights[ie];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    cin >> is >> ie;
    graph.resize(n + 1);
    for(int i=0;i<m;i++){
        int a, b, k;
        cin >> a >> b >> k;
        graph[a].emplace_back(b, k);
        graph[b].emplace_back(a, k);
    }
    int result = solve();
    if(result == -1)
        result = 0;
    cout << result << "\n";
    return 0;
}