#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

vector<vector<int>> farm;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    farm.resize(n + 1, vector<int>(m + 1));
    
    priority_queue<pair<int, pair<int, int>>>pq;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> farm[i][j];
        }
    }
    
    int k;
    cin >> k;
    for(int i=1;i<=n;i++){
        if(farm[i][1] != 0)
        {
            pq.push({farm[i][1], {i, 1}});
            farm[i][1] = 0;
        }
        if(farm[i][m] != 0){
            pq.push({farm[i][m], {i, m}});
            farm[i][m] = 0;
        }
    }
    
    for(int i=1;i<=m-1;i++){
        if(farm[1][i] != 0){
            pq.push({farm[1][i], {1, i}});
            farm[1][i] = 0;
        }
        if(farm[n][i] != 0){
            pq.push({farm[n][i], {n, i}});
            farm[n][i] = 0;
        }
    }
    
    vector<pair<int, int>> positions;
    for(int i=0;i<k;i++){
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        positions.emplace_back(y, x);
        pq.pop();
        
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny <= 0 || nx <= 0 || ny > n || nx > m) continue;
            if(farm[ny][nx] == 0) continue;
            pq.push({farm[ny][nx], {ny, nx}});
            farm[ny][nx] = 0;
        }
    }
    
    
    for(int i=0;i<positions.size();i++){
        cout << positions[i].first << " " << positions[i].second << "\n";
    }
    return 0;
}