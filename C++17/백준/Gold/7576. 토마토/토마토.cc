#include<iostream>
#include<queue>
#include <algorithm>
#include <limits.h>

using namespace std;

int n, m;
int map[1000][1000] = {0};
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int solve(){
    int result = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] == -1)
                continue;
            if(map[i][j] == 0)
                return -1;
            
            result = max(result, map[i][j]);
        }
    }
    
    result--;
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                q.push({i, j});
            }
        }
    }
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        int nextDay = map[y][x] + 1;
        for(int i=0;i<4;i++){
            int cy = y + dy[i];
            int cx = x + dx[i];
            
            if(cy < 0 || cx < 0 || cy >= n || cx >= m)
                continue;
            if(map[cy][cx] != 0)
                continue;
            
            q.push({cy, cx});
            map[cy][cx] = nextDay;
        }
    }
   
    cout << solve() << "\n";
    return 0;
}
