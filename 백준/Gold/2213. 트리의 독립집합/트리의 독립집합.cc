#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> weights;
vector<vector<int>> nodes;

int dp[10001][2] = {0};
vector<int> dpPath[10001][2];
bool visited[10001] = {false};

// 4 1
// 4 1
// a * 2 + 1
// /2, %2
void solve(int s){
    for(int i=0;i<nodes[s].size();i++){
        int e = nodes[s][i];
        
        if(visited[e] == true) continue;
        visited[e] = true;
        solve(e);
        
        
        if(dp[e][0] >= dp[e][1]){
            dpPath[s][0].emplace_back(e*2);
            dp[s][0] += dp[e][0];
        }
        else{
            dpPath[s][0].emplace_back(e*2+1);
            dp[s][0] += dp[e][1];
        }
        dp[s][1] += dp[e][0];
        dpPath[s][1].emplace_back(e * 2);
    }
    
    dp[s][1] += weights[s];
}

void SetPath(vector<int>& path, int s){
    if(s % 2 == 1){
        path.emplace_back(s/2);
    }
    
    vector<int>& nodePath = dpPath[s/2][s%2];
    for(int i=0;i<nodePath.size();i++){
        int e = nodePath[i];
        SetPath(path, e);
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
    if(dp[1][0] < dp[1][1]){
        cout << dp[1][1] << "\n";
        SetPath(path, 3);
    }
    else{
        cout << dp[1][0] << "\n";
        SetPath(path, 2);
    }
    
    sort(path.begin(), path.end());
    for(int i=0;i<path.size();i++){
        cout << path[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
