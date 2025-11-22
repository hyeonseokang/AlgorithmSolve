#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>

using namespace std;

typedef pair<int, int> PAIR;

int n, m, is, ie;

vector<vector<PAIR>> graph;
priority_queue<pair<int, pair<int, int>>> pq;
vector<int> parents;

int Find(int x){
    int parent = parents[x];
    if(parent == x)
        return parent;
    
    return parents[parent] = Find(parent);
}

bool Merge(int a, int b){
    int ap = Find(a);
    int bp = Find(b);
    
    if(ap == bp){
        return false;
    }
    
    if(ap < bp){
        parents[bp] = ap;
    }
    else{
        parents[ap] = bp;
    }
    
    return true;
}

int solve(){
    while(!pq.empty()){
        int s = pq.top().second.first;
        int e = pq.top().second.second;
        int k = pq.top().first;
        pq.pop();
        
        if(Merge(s, e)){
            graph[s].emplace_back(e, k);
            graph[e].emplace_back(s, k);
        }
    }
    
    queue<PAIR> q;
    q.push({is, INT_MAX});
    while(!q.empty()){
        int s = q.front().first;
        int k = q.front().second;
        q.pop();
        
        if(s == ie){
            return k;
        }
        
        vector<PAIR>& v = graph[s];
        for(int i=0;i<v.size();i++){
            int e = v[i].first;
            int weight = min(k, v[i].second);
            if(parents[e] != 0){
                parents[e] = 0;
                q.push({e, weight});
            }
        }
    }
    
    return 0;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    cin >> is >> ie;
    graph.resize(n + 1);
    parents.resize(n + 1);
    for(int i=0;i<=n;i++){
        parents[i] = i;
    }
    for(int i=0;i<m;i++){
        int a, b, k;
        cin >> a >> b >> k;
        pq.push({k, {a, b}});
    }
    
    cout << solve() <<"\n";
    
    return 0;
}
