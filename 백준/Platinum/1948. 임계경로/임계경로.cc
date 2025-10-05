#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int dp[10001];
int dp2[10001];
int n, m;
bool visited[100000] = {false};
vector<vector<pair<int, pair<int, int>>>> map;
int startPoint, endPoint;
int solve(int e){
    if(e == startPoint){
        return 0;
    }
    int& ret = dp[e];
    
    if(ret != -1){
        return ret;
    }
    
    vector<pair<int, pair<int,int>>>& node = map[e];
    
    ret = 0;
    for(int i=0;i<node.size();i++){
        int s = node[i].first;
        int dist = node[i].second.first;
        int nDist = solve(s) + dist;
        ret = max(ret, nDist);
    }
    
    return ret;
}

int result2 =  0;
void solve2(int e, int dist){
    vector<pair<int, pair<int, int>>>& node = map[e];
    for(int i=0;i<node.size();i++){
        int s = node[i].first;
        int d = node[i].second.first;
        int index = node[i].second.second;
        if(dist - d == dp[s]){
            result2++;
            if(visited[s] == true) continue;
            visited[s] = true;
            solve2(s, dist - d);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    cin >> n;
    cin >> m;
    map.resize(n + 1);
    for(int i=0;i<m;i++){
        int to, from, dist;
        cin >> to >> from >> dist;
        map[from].emplace_back(to, make_pair(dist, i));
    }
    cin >> startPoint >> endPoint;
    dp[startPoint] = 0;
    dp2[startPoint] = 0;
    int result = solve(endPoint);
    solve2(endPoint, result);
    cout << result << "\n" << result2 << "\n";
    
    return 0;
}
