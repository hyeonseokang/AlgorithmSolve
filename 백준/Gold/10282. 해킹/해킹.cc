#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int t;
int n, d, c;
vector<vector<pair<int, int>>> dependencies;

void BFS(){
    priority_queue<pair<int, int>,  vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, c});
    vector<bool> visited(n + 1, false);
    
    int lastTime = 0;
    int virusCnt = 0;
    
    while(!pq.empty()){
        int currentTime = pq.top().first;
        int s = pq.top().second;
        pq.pop();
        if(visited[s] == true)
            continue;
        
        visited[s] = true;
        lastTime = currentTime;
        virusCnt++;
        
        vector<pair<int, int>>& dependency = dependencies[s];
        for(int i=0;i<dependency.size();i++){
            int e = dependency[i].first;
            if(visited[e] == true) continue;
            
            int nTime = dependency[i].second + currentTime;
            pq.push({nTime, e});
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
