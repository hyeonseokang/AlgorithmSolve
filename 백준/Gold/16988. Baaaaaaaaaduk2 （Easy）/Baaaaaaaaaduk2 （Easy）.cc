#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int n, m;
int boards[20][20] = {0};
bool visited[20][20] = {0};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<pair<int, int>> blanks;
vector<pair<int, int>> whiteBlanks;

pair<int, int> selectStones[2];

bool IsOutSide(int y, int x){
    return y < 0 || x < 0 || y >= n || x >= m;
}

int GetDeadStone(int sy, int sx){
    queue<pair<int, int>> q;
    int result = 0;
    visited[sy][sx] = true;
    q.push({sy, sx});
    
    bool isEnd = false;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        result++;
        q.pop();
        
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(IsOutSide(ny, nx) || visited[ny][nx] == true)
                continue;
            if(boards[ny][nx] == 1)
                continue;
            if(boards[ny][nx] == 0)
                isEnd = true;
            else{
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }
    
    if(isEnd)
        return 0;
    
    return result;
}

int GetDeadStonePair(int len){
    memset(visited, false, sizeof(visited));
    int result = 0;
    
    for(int i=0;i<len;i++){
        for(int k=0;k<4;k++){
            int ny = selectStones[i].first + dy[k];
            int nx = selectStones[i].second + dx[k];
            
            if(IsOutSide(ny, nx) || visited[ny][nx] == true)
                continue;
            if(boards[ny][nx] == 2){
                result += GetDeadStone(ny, nx);
            }
        }
    }
    
    return result;
}


int solve(int len, int i){
    if(len == 2){
        return GetDeadStonePair(len);
    }
    
    int result = GetDeadStonePair(len);
    for(;i<blanks.size();i++){
        selectStones[len] = blanks[i];
        boards[blanks[i].first][blanks[i].second] = 1;
        result = max(result, solve(len + 1, i + 1));
        boards[blanks[i].first][blanks[i].second] = 0;
    }
    
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> boards[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(boards[i][j] != 0) continue;
            
            bool isWhiteBlank = true;
            for(int k=0;k<4;k++){
                int y = i + dy[k];
                int x = j + dx[k];
                if(IsOutSide(y, x)) continue;
                
                if(boards[y][x] == 2){
                    isWhiteBlank = false;
                    break;
                }
            }
            
            if(isWhiteBlank)
                whiteBlanks.emplace_back(i, j);
            else
                blanks.emplace_back(i, j);
        }
    }
    
    cout << solve(0, 0) << "\n";
    
    
    
    return 0;
}
