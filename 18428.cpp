#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int n;
char board[6][6];
vector<pair<int, int>> teachers;

// 장애물 3개를 설치 했을때 현재 감시를 피할수 있는지 확인
bool CheckDetection(){
    for(int i=0;i<teachers.size();i++){
        int y = teachers[i].first;
        int x = teachers[i].second;
        
        for(int k=0;k<4;k++){
            int sy = y;
            int sx = x;
            
            while(true){
                sy += dy[k];
                sx += dx[k];
                
                if(sy < 0 || sx < 0 || sy >= n || sx >= n)
                    break;
                if(board[sy][sx] == 'O')
                    break;
                if(board[sy][sx] == 'S')
                    return false;
            }
        }
    }
    
    return true;
}

// 장애물 설치하는 함수
bool PlaceObstacles(int len, int i){
    if(len == 3){
        return CheckDetection();
    }
    
    for(;i<n*n;i++){
        int y = i / n;
        int x = i % n;
        
        if(board[y][x] == 'X'){
            board[y][x] = 'O';
            if(PlaceObstacles(len + 1, i + 1) == true)
                return true;
            board[y][x] = 'X';
        }
    }
    
    return false;
}

// main에서 사용 장애물을 3개 설치할수있을때 감시를 피할수있는지
bool IsDetectionAvoidable(){
    return PlaceObstacles(0, 0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            if(board[i][j] == 'T')
                teachers.emplace_back(i, j);
        }
    }
    
    if(IsDetectionAvoidable() == true)
        cout << "YES\n";
    else
        cout << "NO\n";
    
    return 0;
}
