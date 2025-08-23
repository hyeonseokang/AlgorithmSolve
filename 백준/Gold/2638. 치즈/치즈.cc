#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m;
int boards[100][100] = {0};
int airCounts[100][100] = {0};
bool visited[100][100] = {false};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
vector<pair<int, int>> cheeses;
int cnt = 0;

void BFS(){
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            
            if(visited[ny][nx] == true) continue;
            if(boards[ny][nx] == 1 && airCounts[ny][nx] < 2){
                airCounts[ny][nx]++;
                if(airCounts[ny][nx] >= 2){
                    cheeses.emplace_back(ny, nx);
                }
                continue;
            }
            
            if(boards[ny][nx] == 0){
                cnt--;
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    cnt = n * m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> boards[i][j];
        }
    }
    
    q.push({0,0});
    cnt--;
    visited[0][0] = true;
    int timeCnt = 0;
    while(cnt > 0){
        timeCnt++;
        BFS();
        
        for(int i=0;i<cheeses.size();i++){
            int y = cheeses[i].first;
            int x = cheeses[i].second;
            boards[y][x] = 0;
            cnt--;
            visited[y][x] = true;
            q.push({y, x});
        }
        cheeses.clear();
    }
    cout << timeCnt << "\n";
    
    return 0;
}

