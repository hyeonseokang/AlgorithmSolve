#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<limits.h>

using namespace std;
int n, m;
int s, e;
int map[500][500];
int dist[500];
vector<int> parent[500];
bool visited[500] = {false};
void Dikstra(){
    memset(visited, false, sizeof(visited));
    for(int i=0;i<n;i++){
        dist[i] = INT_MAX;
        parent[i].clear();
        parent[i].emplace_back(0);
    }
    dist[s] = 0;
    parent[s][0] = s;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    
    while(!q.empty()){
        int ns = q.front();
        int d = dist[ns];
        visited[ns] = false;
        q.pop();
        
        for(int i=0;i<n;i++){
            if(map[ns][i] == 0) continue;
            
            int newDist = d + map[ns][i];
            if(newDist < dist[i]){
                parent[i].clear();
                parent[i].emplace_back(ns);
                dist[i] = newDist;
                if(visited[i] == false){
                    q.push(i);
                    visited[i] = true;
                }
            }
            else if(newDist == dist[i])
                parent[i].emplace_back(ns);
        }
    }
}

void RemoveShortestPath(){
    queue<int> q;
    q.push(e);
    visited[e] = true;
    while(!q.empty()){
        int to = q.front();
        q.pop();
        if(parent[to].size() == 1 && parent[to][0] == to) continue;
        for(int p:parent[to]){
            map[p][to] = 0;
            if(visited[p] == false){
                q.push(p);
                visited[p] = true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(true){
        memset(map, 0, sizeof(map));
        cin >> n >> m;
        cin >> s >> e;
        for(int i=0;i<m;i++){
            int from, to, d;
            cin >> from >> to >> d;
            map[from][to] = d;
        }
        
        if(n == 0)
            break;
        Dikstra();
        RemoveShortestPath();
        Dikstra();
        int result = dist[e];
        if(result == INT_MAX)
            result = -1;
        cout << result << "\n";
    }
    
    return 0;
}
