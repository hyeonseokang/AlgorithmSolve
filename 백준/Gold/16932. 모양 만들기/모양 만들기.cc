#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int n, m;
vector<int> parents;
map<int, int> shapeSize;

int Find(int x){
    int parent = parents[x];
    if(parent == x){
        return parent;
    }
    
    return parents[parent] = Find(parent);
}

void Merge(int a, int b){
    int aParent = Find(a);
    int bParent = Find(b);
    
    if(aParent <= bParent){
        parents[bParent] = aParent;
    }
    else{
        parents[aParent] = bParent;
    }
}

bool boards[1000][1000];
bool visited[1000][1000] = {false};
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void BFS(int sy, int sx){
    visited[sy][sx] = true;
    queue<pair<int, int>> q;
    int parent = sy * m + sx;
    shapeSize[parent] = 0;
    q.push({sy, sx});
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        shapeSize[parent]++;
        q.pop();
        
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n  || nx >= m) continue;
            if(visited[ny][nx] == true || boards[ny][nx] == 0) continue;
            
            visited[ny][nx] = true;
            q.push({ny, nx});
            Merge(parent, ny * m + nx);
        }
    }
}

int GetChangedMaxShape(int y, int x){
    int result = 1;
    
    vector<int> mergeParents;
    
    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if(boards[ny][nx] == 0) continue;
        
        int parent = Find(ny * m + nx);
        bool isAlreadyShape = false;
        for(int j=0;j<mergeParents.size();j++){
            if(mergeParents[j] == parent){
                isAlreadyShape = true;
            }
        }
        if(isAlreadyShape)
            continue;
        
        result += shapeSize[parent];
        mergeParents.emplace_back(parent);
    }
    
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    parents.resize(n * m);
    for(int i=0;i<n*m;i++){
        parents[i] = i;
    }
    
    
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
    int result = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(boards[i][j] == true) continue;
            
            result = max(result, GetChangedMaxShape(i, j));
        }
    }
    
    cout << result << "\n";
    
    
    return 0;
}
