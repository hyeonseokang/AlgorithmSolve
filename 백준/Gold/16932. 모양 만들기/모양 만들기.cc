#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int n, m;
vector<int> shapeSize(1, 0);
bool boards[1000][1000];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int shapeNumbers[1000][1000] = {0};
int shapeCnt = 0;

void BFS(int sy, int sx){
    shapeNumbers[sy][sx] = ++shapeCnt;
    shapeSize.emplace_back(0);
    queue<pair<int, int>> q;
    int parent = shapeNumbers[sy][sx];
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
            if(shapeNumbers[ny][nx] != 0 || boards[ny][nx] == 0) continue;
            
            shapeNumbers[ny][nx] = parent;
            q.push({ny, nx});
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
        
        int shapeNumber = shapeNumbers[ny][nx];
        
        bool isAlreadyShape = false;
        for(int j=0;j<mergeParents.size();j++){
            if(mergeParents[j] == shapeNumber){
                isAlreadyShape = true;
            }
        }
        if(isAlreadyShape)
            continue;
        
        result += shapeSize[shapeNumber];
        mergeParents.emplace_back(shapeNumber);
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
            if(shapeNumbers[i][j] != 0 || boards[i][j] == 0) continue;
            
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
