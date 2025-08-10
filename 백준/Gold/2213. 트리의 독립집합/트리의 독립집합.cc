#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n;
vector<int> weights;
vector<vector<int>> nodes;

int dp[10001][2] = {0};
bool visited[10001] = {false};

void solve(int s){
    for(int i=0;i<nodes[s].size();i++){
        int e = nodes[s][i];
        
        if(visited[e] == true) continue;
        visited[e] = true;
        solve(e);
        
        dp[s][0] += max(dp[e][0], dp[e][1]);
        dp[s][1] += dp[e][0];
    }
    
    dp[s][1] += weights[s];
}

void SetPath(vector<int>& path, int s, int prev){
    if(dp[s][1] > dp[s][0] && visited[prev] == false){
        path.emplace_back(s);
        visited[s] = true;
    }
    
    for(int i=0;i<nodes[s].size();i++){
        int e = nodes[s][i];
        if(e == prev) continue;
        
        SetPath(path, e, s);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    weights.resize(n + 1);
    nodes.resize(n + 1);
    
    for(int i=1;i<=n;i++){
        cin >> weights[i];
    }
    
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        nodes[a].emplace_back(b);
        nodes[b].emplace_back(a);
    }
    visited[1] = true;
    solve(1);
    vector<int> path;
    memset(visited, false, sizeof(visited));
    cout << max(dp[1][0], dp[1][1]) << "\n";
    SetPath(path, 1, 0);
    
    sort(path.begin(), path.end());
    for(int i=0;i<path.size();i++){
        cout << path[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
