#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int n, m, k;
int mine[1000][1000];
int mineHardMap[1000][1000];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[1000][1000];

typedef pair<int, pair<int, int>> PAIR;

int CalculateMineHardMap(){
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
    for(int i=0;i<m;i++){
        pq.push({mine[0][i], {0, i}});
        mineHardMap[0][i] = mine[0][i];
    }
    for(int i=1;i<n;i++){
        pq.push({mine[i][0], {i, 0}});
        mineHardMap[i][0] = mine[i][0];
        pq.push({mine[i][m-1], {i, m-1}});
        mineHardMap[i][m-1] = mine[i][m-1];
    }
    
    int cnt = 0;
    while(!pq.empty()){
        int hardness = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        cnt ++;
        if(cnt >= k){
            return hardness;
        }
        pq.pop();
        
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(mineHardMap[ny][nx] != -1) continue;
            
            mineHardMap[ny][nx] = max(mine[ny][nx], hardness);
            pq.push({mineHardMap[ny][nx], {ny, nx}});
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mine[i][j];
            mineHardMap[i][j] = -1;
        }
    }
    int result = CalculateMineHardMap();
    cout << result << "\n";
    return 0;
}
