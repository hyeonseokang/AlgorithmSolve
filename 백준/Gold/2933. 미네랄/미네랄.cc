#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<limits.h>
#include<cstring>

using namespace std;
int r, c;
char boards[100][100];
int n;
int cnt = 0;
bool visited[100][100];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> clusters;


void bfs(int sy, int sx){
    queue<pair<int, int>> q;
    q.push({sy, sx});
    clusters.emplace_back(sy, sx);
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        boards[y][x] = '0' + cnt;
        q.pop();
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if(visited[ny][nx] == true || boards[ny][nx] == '.') continue;
            
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    
    cnt++;
}

void RefreshBoard(){
    memset(visited, false, sizeof(visited));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(visited[i][j] == true || boards[i][j] == '.') continue;
            visited[i][j] = true;
            bfs(i, j);
        }
    }
}


void Fall(int num){
    int sy = clusters[num].first;
    int sx = clusters[num].second;
    
    queue<pair<int, int>> q;
    q.push({sy, sx});
    memset(visited, false, sizeof(visited));
    visited[sy][sx] = true;
    vector<pair<int, int>> cluster;
    cluster.clear();
    int movePosY = r;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        cluster.emplace_back(y, x);
        int i;
        for(i=y;i<r;i++){
            if(boards[i][x] != boards[y][x] && boards[i][x] != '.'){
                movePosY = min(movePosY, i - y - 1);
                break;
            }
        }
        if(i == r){
            movePosY = min(movePosY, r - y - 1);
        }
        
        for(i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if(visited[ny][nx] == true || boards[sy][sx] != boards[ny][nx]) continue;
            
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    
    if(movePosY == 0) return;
    sort(cluster.begin(), cluster.end(), greater<pair<int, int>>());
    for(int i=0;i<cluster.size();i++){
        int y = cluster[i].first;
        int x = cluster[i].second;
        boards[y + movePosY][x] = boards[y][x];
        boards[y][x] = '.';
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> r >> c;
    for(int i=0;i<r;i++){
        string s;
        cin >> s;
        for(int j=0;j<c;j++){
            boards[i][j] = s[j];
        }
    }
    
    cin >> n;
    bool isLeft = true;
    for(int i=0;i<n;i++){
        int h;
        cin >> h;
        h = r - h;
        if(isLeft){
            for(int j=0;j<c;j++){
                if(boards[h][j] != '.'){
                    boards[h][j] = '.';
                    break;
                }
            }
        }
        else{
            for(int j=c-1;j>=0;j--){
                if(boards[h][j] != '.'){
                    boards[h][j] = '.';
                    break;
                }
            }
        }
        isLeft = !isLeft;
        clusters.clear();
        cnt = 0;
        RefreshBoard();
        for(int i=0;i<cnt;i++){
            Fall(i);
        }
    }
    
    for(int y=0;y<r;y++){
        for(int x =0;x<c;x++){
            if(boards[y][x] != '.')
                cout << "x";
            else
                cout << boards[y][x];
        }
        cout << "\n";
    }
    
    return 0;
}
