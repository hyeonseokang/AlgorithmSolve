#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>

using namespace std;

int t;
int n, d, c;
vector<vector<pair<int, int>>> dependencies;

void BFS(){
    priority_queue<pair<int, int>,  vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, c});
    
    vector<int> dists(n + 1, INT_MAX);
    dists[c] = 0;
    
    while(!pq.empty()){
        int currentTime = pq.top().first;
        int s = pq.top().second;
        pq.pop();
        
        if(dists[s] < currentTime)
            continue;
        
        vector<pair<int, int>>& dependency = dependencies[s];
        for(int i=0;i<dependency.size();i++){
            int e = dependency[i].first;
            int nTime = dependency[i].second + currentTime;
            if(dists[e] > nTime){
                dists[e] = nTime;
                pq.push({nTime, e});
            }
        }
    }
    
    int lastTime = 0;
    int virusCnt = 0;
    for(int i=1;i<dists.size();i++){
        if(dists[i] != INT_MAX){
            virusCnt++;
            lastTime = max(lastTime, dists[i]);
        }
    }
    cout << virusCnt << " " << lastTime << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    while(t--){
        cin >> n >> d >> c;
        dependencies.clear();
        dependencies.resize(n + 1);
        
        for(int i=0;i<d;i++){
            int a, b, s;
            cin >> a >> b >> s;
            dependencies[b].emplace_back(a, s);
        }
        
        BFS();
    }
    
    return 0;
}
