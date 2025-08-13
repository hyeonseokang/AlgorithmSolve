#include<iostream>
#include<string>
#include<cstring>
#include<queue>

using namespace std;

int n, m;
string board[10];
int dp[10][10][10][10] = {0};

typedef pair<int, int> PAIR;
PAIR blue, red, hole;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool IsHolePos(const PAIR& pos){
    return board[pos.first][pos.second] == 'O';
}

void Move(PAIR& pos, PAIR& target, int direction){
    if(board[pos.first][pos.second] == 'O')
        return;
    
    int ny = pos.first + dy[direction];
    int nx = pos.second + dx[direction];
    while(board[ny][nx] != '#'){
        if(board[ny][nx] != 'O' && target.first == ny && target.second == nx)
            break;
        pos = {ny, nx};
        if(board[ny][nx] == 'O')
            break;
        ny += dy[direction];
        nx += dx[direction];
    }
}

int solve(PAIR& r, PAIR& b){
    queue<pair<PAIR, PAIR>> q;
    dp[r.first][r.second][b.first][b.second] = 0;
    q.push({r, b});
    while(!q.empty()){
        PAIR rPos = q.front().first;
        PAIR bPos = q.front().second;
        q.pop();
        int cost = dp[rPos.first][rPos.second][bPos.first][bPos.second];
        
        for(int i=0;i<4;i++){
            PAIR cr = rPos;
            PAIR cb = bPos;
            Move(cr, cb, i);
            Move(cb, cr, i);
            Move(cr, cb, i);
            
            bool isRedHole = IsHolePos(cr);
            bool isBlueHole = IsHolePos(cb);
            
            if(isBlueHole)
                continue;
            else if(isRedHole)
                return cost + 1;
            
            if(dp[cr.first][cr.second][cb.first][cb.second] != -1)
                continue;
            
            q.push({cr, cb});
            dp[cr.first][cr.second][cb.first][cb.second] = cost + 1;
        }
    }
    
    
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(dp, -1, sizeof(dp));
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> board[i];
        for(int j=0;j<m;j++){
            if(board[i][j] == 'B'){
                board[i][j] = '.';
                blue = {i, j};
            }
            else if(board[i][j] == 'R'){
                board[i][j] = '.';
                red = {i, j};
            }
            else if(board[i][j] == 'O')
                hole = {i, j};
        }
    }
    
    int result = solve(red, blue);
    if(result != -1 && result <= 10){
        cout << "1\n";
    }
    else{
        cout << "0\n";
    }
    
    return 0;
}

