#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int n, m;

int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool isCloudCell[50][50] = {false};

// 초기 구름 추가
void Init(vector<pair<int, int>>& clouds){
    for(int y=n-2;y<n;y++){
        for(int x=0;x<2;x++){
            clouds.emplace_back(y, x);
        }
    }
}

// 구름 이동
void Move(vector<pair<int, int>>& clouds, int direction, int dist){
    for(int i=0;i<clouds.size();i++){
        int y = clouds[i].first + n * 51 + dy[direction] * dist;
        int x = clouds[i].second + n * 51 + dx[direction] * dist;
        
        y %= n;
        x %= n;
        
        clouds[i] = {y, x};
    }
}

// 비 내리기 (구름 있는 칸에 물 양 1 증가)
void StartRainFall(vector<vector<int>>& cells, vector<pair<int, int>>& clouds){
    for(int i=0;i<clouds.size();i++){
        int y = clouds[i].first;
        int x = clouds[i].second;
        
        cells[y][x]++;
    }
}

void ClearClouds(vector<pair<int, int>>& clouds){
    memset(isCloudCell, false, sizeof(isCloudCell));
    for(int i=0;i<clouds.size();i++){
        int y = clouds[i].first;
        int x = clouds[i].second;
        isCloudCell[y][x] = true;
    }
    clouds.clear();
}

bool IsOutSide(int y, int x){
    return y < 0 || x < 0 || y >= n || x >= n;
}

// 물 복사 버그 마법 시전
void CastWaterClone(vector<vector<int>>& cells, vector<pair<int,int>>& clouds){
    vector<pair<int, int>> cloneWaterCell;
    cloneWaterCell.reserve(n * n * 4);
    for(int i=0;i<clouds.size();i++){
        int y = clouds[i].first;
        int x = clouds[i].second;
        
        // 대각선만 처리
        for(int j=1;j<8;j+=2){
            int ny = y + dy[j];
            int nx = x + dx[j];
            
            if(IsOutSide(ny, nx) == true || cells[ny][nx] <= 0)
                continue;
            
            cloneWaterCell.emplace_back(y, x);
        }
    }
    
    for(int i=0;i<cloneWaterCell.size();i++){
        int y = cloneWaterCell[i].first;
        int x = cloneWaterCell[i].second;
        
        cells[y][x]++;
    }
}

// 새로운 구름 생성 물의 양이 2 이상, 그 전에 구름 아니었던 곳
void SpawnClouds(vector<vector<int>>& cells, vector<pair<int, int>>& clouds){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cells[i][j] < 2 || isCloudCell[i][j] == true)
                continue;
            
            clouds.emplace_back(i, j);
            cells[i][j] -= 2;
        }
    }
}

void Print(const vector<vector<int>>& cells){
    int waterSum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            waterSum += cells[i][j];
        }
    }
    
    cout << waterSum << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    vector<vector<int>> cells(n, vector<int>(n, 0));
    vector<pair<int, int>> clouds;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> cells[i][j];
        }
    }
    
    Init(clouds);
    
    for(int i=0;i<m;i++){
        int direction, dist;
        cin >> direction >> dist;
        
        Move(clouds, direction-1, dist);
        StartRainFall(cells, clouds);
        CastWaterClone(cells, clouds);
        ClearClouds(clouds);
        SpawnClouds(cells, clouds);
    }
    
    Print(cells);
    
    return 0;
}
