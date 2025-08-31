#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<limits.h>

using namespace std;

int n, m;
string maps[50];

int startDP[50][50][4] = {0};
int giftDP[50][50][4] = {0};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

typedef pair<int, int> POS;
POS startPos;
vector<POS> giftPos;

int GetCost(POS secondGiftPos){
    int result = INT_MAX;
    for(int i=0;i<4;i++){
        int cost = giftDP[secondGiftPos.first][secondGiftPos.second][i];
        if(cost != -1){
            result = min(result, cost);
        }
    }
    
    return result;
}


void Solve(int dp[50][50][4], POS start){
    priority_queue<pair<pair<int,  int>, POS>,
    vector<pair<pair<int,  int>, POS>>,
    greater<pair<pair<int,  int>, POS>>> pq;
    
    for(int i=0;i<4;i++){
        int cost = dp[start.first][start.second][i];
        if(cost != -1){
            pq.push({{cost, i}, start});
        }
    }
    if(pq.empty()){
        pq.push({{0, -1}, start});
    }
    
    while(!pq.empty()){
        POS s = pq.top().second;
        int dir = pq.top().first.second;
        int cost = pq.top().first.first;
        int nCost = cost + 1;
        pq.pop();
        
        for(int i=0;i<4;i++){
            if(i == dir) continue;
            
            int ny = s.first + dy[i];
            int nx = s.second + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(maps[ny][nx] == '#') continue;
            
            if(dp[ny][nx][i] == -1){
                dp[ny][nx][i] = nCost;
                pq.push({{nCost, i}, {ny, nx}});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(startDP, -1, sizeof(startDP));
    memset(giftDP, -1, sizeof(giftDP));
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> maps[i];
        for(int j=0;j<m;j++){
            if(maps[i][j] == 'S'){
                startPos = {i, j};
            }
            else if(maps[i][j] == 'C'){
                giftPos.emplace_back(i, j);
            }
        }
    }
    
    Solve(startDP, startPos);
    
    bool isB = false;
    for(int i=0;i<4;i++){
        if(startDP[giftPos[0].first][giftPos[0].second][i] != -1)
            isB = true;
        giftDP[giftPos[0].first][giftPos[0].second][i] = startDP[giftPos[0].first][giftPos[0].second][i];
    }
    if(isB)
        Solve(giftDP, giftPos[0]);
    int result = GetCost(giftPos[1]);
    
    memset(giftDP, -1, sizeof(giftDP));
    isB = false;
    for(int i=0;i<4;i++){
        if(startDP[giftPos[1].first][giftPos[1].second][i] != -1)
            isB = true;
        giftDP[giftPos[1].first][giftPos[1].second][i] = startDP[giftPos[1].first][giftPos[1].second][i];
    }
    if(isB == true)
        Solve(giftDP, giftPos[1]);
    result = min(result, GetCost(giftPos[0]));
    
    if(result == INT_MAX)
        result = -1;
    cout << result << "\n";
    
    return 0;
}


