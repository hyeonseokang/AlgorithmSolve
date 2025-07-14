#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
int w,h;

int layouts[100][100] = {0};
bool visited[100][100] = {false};

int dy[2][6] = {
    {-1, -1, 0, 1, 1, 0},
    {-1, -1, 0, 1, 1, 0},
};
int dx[2][6] = {
    {0, 1, 1, 1, 0, -1},
    {-1, 0, 1, 0, -1, -1},
};

int houses[100][100] = {0};
int result = 0;

void BFS(int sy, int sx)
{
    visited[sy][sx] = true;
    queue<pair<int, int>> q;
    q.push({sy, sx});
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        int hIdx = y % 2;
        for(int i=0;i<6;i++){
            int ny = y + dy[hIdx][i];
            int nx = x + dx[hIdx][i];
            
            if(ny < 0 || nx < 0 || ny >= h || nx >= w || layouts[ny][nx] == 0){
                result++;
                continue;
            }
            if(visited[ny][nx] == true || layouts[ny][nx] == 1)
                continue;
            
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}


void BFS2(int sy, int sx)
{
    int minusResult = 0;
    bool isOutSide = false;
    
    visited[sy][sx] = true;
    queue<pair<int, int>> q;
    q.push({sy, sx});
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        int hIdx = y % 2;
        q.pop();
        for(int i=0;i<6;i++){
            int ny = y + dy[hIdx][i];
            int nx = x + dx[hIdx][i];
            
            if(ny < 0 || nx < 0 || ny >= h || nx >= w){
                isOutSide = true;
                continue;
            }
            if(layouts[ny][nx] == 1){
                minusResult++;
                continue;
            }
            if(visited[ny][nx] == true)
                continue;;
            
            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
    
    if(isOutSide == false){
        result -= minusResult;
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> w >> h;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> layouts[i][j];
        }
    }
    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(visited[i][j] == true) continue;
            
            if(layouts[i][j] == 1)
                BFS(i, j);
            else
                BFS2(i, j);
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
