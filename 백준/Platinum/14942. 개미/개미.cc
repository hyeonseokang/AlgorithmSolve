#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<unordered_map>

using namespace std;

int n;
vector<int> energies;
vector<vector<pair<int, int>>> map;
int parents[100001][18];
int dists[100001][18];
bool visited[100001] = {false};
void InitParents(){
    parents[1][0] = 0;
    dists[1][0] = 0;
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while(!q.empty()){
        int s = q.front();
        q.pop();
        
        vector<pair<int, int>>& graph = map[s];
        for(auto& p: graph){
            int e = p.first;
            int dist = p.second;
            if(visited[e] == true) continue;
            q.push(e);
            visited[e] = true;
            int parent = s;
            parents[e][0] = parent;
            dists[e][0] = dist;
            for(int i=1;i<18;i++){
                if(parent == 0) break;
                parents[e][i] = parents[parent][i-1];
                dists[e][i] = dists[e][i-1] + dists[parents[e][i-1]][i-1];
                parent = parents[parent][i-1];
            }
        }
    }
}

int solve(int s){
    int remainEnergy = energies[s];
    int parent = s;
    while(true){
        int i = 0;
        for(;i<18;i++){
            if(parents[parent][i] == 0) break;
            if(dists[parent][i] > remainEnergy) break;
        }
        if(i == 0) break;
        remainEnergy -= dists[parent][i-1];
        parent = parents[parent][i-1];
    }
    return parent;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    energies.resize(n + 1);
    map.resize(n + 1);
    for(int i=1;i<=n;i++){
        cin >> energies[i];
    }
    for(int i=1;i<n;i++){
        int to, from, dist;
        cin >> to >> from >> dist;
        map[to].emplace_back(from, dist);
        map[from].emplace_back(to, dist);
    }
    
    InitParents();
    for(int i=1;i<=n;i++){
        cout << solve(i) << "\n";
    }
    return 0;
}
