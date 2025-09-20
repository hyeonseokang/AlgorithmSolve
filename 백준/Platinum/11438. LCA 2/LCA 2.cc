#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>

constexpr int MAX_NODE = 100001;
using namespace std;
vector<int> nodes[MAX_NODE];
int depth[MAX_NODE];
int parent[MAX_NODE][18];
int n, m;

void InitNode(){
    queue<int> q;
    q.push(1);
    depth[1] = 1;
    parent[1][0] = 0;
    
    while(!q.empty()){
        int s = q.front();
        q.pop();
        int p = parent[s][0];
        for(int i=1;i<18;i++){
            if(p == 0) break;
            parent[s][i] = parent[p][i-1];
            p = parent[s][i];
        }
        
        int nextDepth = depth[s] + 1;
        for(int i=0;i<nodes[s].size();i++){
            int e = nodes[s][i];
            if(parent[s][0] == e) continue;
            depth[e] = nextDepth;
            parent[e][0] = s;
            q.push(e);
        }
    }
}

int solve(int a, int b){
    if(depth[a] > depth[b])
        swap(a, b);
    
    
    // depth 맞추기
    int diff = depth[b] - depth[a];
    for(int i=0;i<18;i++){
        if(diff % 2 == 1){
            b = parent[b][i];
        }
        diff = (diff >> 1);
        if(diff == 0) break;
    }
    
    if(a == b)
        return a;
    
    while(parent[a][0] != parent[b][0]){
        for(int i=1;i<18;i++){
            if(parent[a][i] == parent[b][i]){
                a = parent[a][i-1];
                b = parent[b][i-1];
                break;
            }
        }
    }
    
    return parent[a][0];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i=1;i<n;i++){
        int from, to;
        cin >> from >> to;
        nodes[from].emplace_back(to);
        nodes[to].emplace_back(from);
    }
    InitNode();
    
    solve(15, 1);
    cin >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
    
    
    return 0;
}
