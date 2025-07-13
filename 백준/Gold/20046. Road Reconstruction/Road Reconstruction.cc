#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int m, n;
int roads[1000][1000] = {0};
bool visited[1000][1000] = {false};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

typedef pair<int, pair<int, int>> Road;

int GetRoadCost(int y, int x){
    if(roads[y][x] == 0)
        return 0;
    else if(roads[y][x] == 1 || roads[y][x] == 2)
        return roads[y][x];
    
    return -1;
}
void Solve(){
    priority_queue<Road, vector<Road>, greater<Road>> pq;
    int startCost = GetRoadCost(0, 0);
    if(startCost != -1)
        pq.push({startCost, {0,0}});
    visited[0][0] = true;
    
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        if(y == m - 1 && x == n - 1){
            cout << cost << "\n";
            return;
        }
        
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= m || nx >= n)
                continue;
            
            int nCost = GetRoadCost(ny, nx);
            if(visited[ny][nx] == true || nCost == -1)
                continue;
            
            visited[ny][nx] = true;
            pq.push({cost + nCost, {ny, nx}});
        }
    }
    
    cout << "-1\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> m >> n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> roads[i][j];
        }
    }
    
    Solve();
    
    return 0;
}
