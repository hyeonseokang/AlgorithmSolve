#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int cnts[500][500] = {0};
int results[500][500] = {0};

typedef pair<int, pair<int, int>> PAIR;
priority_queue<PAIR, vector<PAIR>> pq;

int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int r, c;
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> cnts[i][j];
            pq.push({cnts[i][j], {i, j}});
            results[i][j] = 1;
        }
    }
    
    while(!pq.empty()){
        int cnt = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        
        int minValue = cnts[y][x];
        int minY = 0, minX = 0;
        for(int i=0;i<8;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            
            if(cnts[ny][nx] < minValue){
                minValue = cnts[ny][nx];
                minY = ny;
                minX = nx;
            }
        }
        
        if(minValue != cnts[y][x]){
            results[minY][minX] += results[y][x];
            results[y][x] = 0;
        }
    }
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << results[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}