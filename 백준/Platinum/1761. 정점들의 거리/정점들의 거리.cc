#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>

using namespace std;

int n;
vector<unordered_map<int, int>> nodes;
pair<int, int> parent[40001][17];
int depth[40001];

void SetParent(int s){
    int p = parent[s][0].first;
    int dist = parent[s][0].second;
    
    for(int i=1;i<17;i++){
        if(p == 0) break;
        parent[s][i] = {
            parent[p][i-1].first,
            parent[p][i-1].second + dist
        };
        dist = parent[s][i].second;
        p = parent[s][i].first;
    }
}

void Init(){
    queue<int> q;
    q.push(1);
    parent[1][0] = {0, 0};
    depth[1] = 1;
    
    while(!q.empty()){
        int s = q.front();
        SetParent(s);
        q.pop();
        unordered_map<int, int>& startMap = nodes[s];
        int nextDepth = depth[s] + 1;
        for(const pair<int,int> p: startMap){
            int e = p.first;
            int dist = p.second;
            if(parent[s][0].first == e) continue;
            parent[e][0] = {s, dist};
            depth[e] = nextDepth;
            q.push(e);
        }
    }
}

int solve(int a, int b){
    if(depth[a] == 0 || depth[b] == 0)
        return 0;
    
    if(depth[a] > depth[b])
        swap(a, b);
    
    int aDist = 0;
    int bDist = 0;
    int diff =  depth[b] - depth[a];
    for(int i=0;i<17;i++){
        if(diff % 2 == 1){
            bDist += parent[b][i].second;
            b = parent[b][i].first;
        }
        diff = diff >> 1;
        if(diff == 0) break;
    }
    if(a == b)
        return aDist + bDist;
    
    for(int i=16;i>=0;i--){
        if(parent[a][i].first != parent[b][i].first){
            aDist += parent[a][i].second;
            bDist += parent[b][i].second;
            
            a = parent[a][i].first;
            b = parent[b][i].first;
        }
    }
    aDist += parent[a][0].second;
    bDist += parent[b][0].second;
    
    
    return aDist + bDist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    nodes.resize(n + 1);
    for(int i=1;i<n;i++){
        int to, from, dist;
        cin >> to >> from >> dist;
        nodes[to][from] = dist;
        nodes[from][to] = dist;
    }
    Init();
    
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        int to, from;
        cin >> to >> from;
        cout << solve(to, from) << "\n";
    }
    
    return 0;
}
