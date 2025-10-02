#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
int boards[10][10] = {0};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[10][10] = {false};
int cnt = 0;

bool IsOutSide(int y, int x){
    return x < 0 || y < 0 || y >= n || x >= m;
}

void BFS(int sy, int sx){
    queue<pair<int, int>> q;
    q.push({sy, sx});
    int num = ++cnt;
    visited[sy][sx] = true;
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        boards[y][x] = num;
        
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(IsOutSide(ny, nx)) continue;
            if(visited[ny][nx] == true || boards[ny][nx] == 0) continue;
            
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

typedef pair<int, pair<int, int>> PAIR;
priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;

void GoStraight(int sy, int sx, int direction){
    int y = sy + dy[direction];
    int x = sx + dx[direction];
    int num = boards[sy][sx];
    int dist = 0;
    
    while(!IsOutSide(y, x)){
        if(boards[y][x] != num && boards[y][x] != 0){
            if(dist < 2)
                return;
            
            pq.push({dist, {num, boards[y][x]}});
            return;
        }
        else if(boards[y][x] == num)
            return;
        
        dist++;
        y += dy[direction];
        x += dx[direction];
    }
}

int parents[7] = {0};

int Find(int x){
    int parent = parents[x];
    if(parent == x)
        return parent;
    
    return parents[parent] = Find(parent);
}

void Merge(int a, int b){
    int aParent = Find(a);
    int bParent = Find(b);
    if(aParent < bParent){
        parents[bParent] = aParent;
    }
    else{
        parents[aParent] = bParent;
    }
}
int MST(){
    for(int i=0;i<=cnt;i++){
        parents[i] = i;
    }
    
    
    int result = 0;
    while(!pq.empty()){
        int dist = pq.top().first;
        int s = pq.top().second.first;
        int e = pq.top().second.second;
        pq.pop();
        
        if(Find(s) != Find(e)){
            result += dist;
            Merge(s, e);
        }
    }
    
    for(int i=1;i<=cnt;i++){
        if(Find(i) != 1){
            return -1;
        }
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
            if(visited[i][j] == true || boards[i][j] == 0) continue;
            
            BFS(i, j);
        }
    }
    
    
    memset(visited, false, sizeof(visited));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num = boards[i][j];
            if(num <= 0) continue;
            
            for(int k=0;k<4;k++){
                GoStraight(i, j, k);
            }
        }
    }
    
    cout << MST() << "\n";
    
    return 0;
}
