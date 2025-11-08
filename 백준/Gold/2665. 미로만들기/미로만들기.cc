#include<iostream>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;
int n;
string miro[50];
bool visited[50][50];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

typedef pair<int, int> PAIR;

int solve(){
    priority_queue<pair<PAIR, PAIR>, vector<pair<PAIR, PAIR>>, greater<pair<PAIR,PAIR>>> pq;
    
    pq.push({{0,0}, {0,0}});
    visited[0][0] = true;
    
    while(!pq.empty()){
        int cnt = pq.top().first.second;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        if(y == n - 1 && x == n - 1){
            return cnt;
        }
        
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(visited[ny][nx] == true) continue;
            
            visited[ny][nx] = true;
            if(miro[ny][nx] == '1'){
                pq.push({{0, cnt}, {ny, nx}});
            }
            else{
                pq.push({{1, cnt + 1}, {ny, nx}});
            }
        }
    }
    
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> miro[i];
    }
    
    cout << solve() << "\n";
    return 0;
}