#include<iostream>
#include<string>
#include<cstring>
#include<limits.h>
#include<queue>

using namespace std;

int n, m;
string boards[500];
int dp[501][501] = {0};

int dy[4] = {0, -1, -1, 0};
int dx[4] = {0, -1, 0, -1};

int dpDy[4] = {1, -1, -1, 1};
int dpDx[4] = {1, -1, 1, -1};
    

struct Node{
    int y, x, cost;
    
    Node(int _y, int _x, int _cost):y(_y), x(_x), cost(_cost){
        
    }
    
    bool operator<(const Node& other)const{
        return cost < other.cost;
    }
    bool operator>(const Node& other)const{
        return cost > other.cost;
    }
};

bool IsOut(int y, int x){
    return y >= n || x >= m || y < 0 || x < 0;
}

int solve(){
    dp[0][0] = {0};
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push(Node(0,0,0));
    
    while(!pq.empty()){
        Node node = pq.top();
        int cost = node.cost;
        pq.pop();
        if(node.y == n && node.x == m){
            return node.cost;
        }
        
        for(int i=0;i<4;i++){
            int nCost = cost;
            int ny = node.y + dy[i];
            int nx = node.x + dx[i];
            
            if(IsOut(ny, nx)) continue;
            if(boards[ny][nx] == '/' && dy[i] == dx[i]) nCost++;
            else if(boards[ny][nx] == '\\' && dy[i] != dx[i]) nCost++;
            
            int dpY = node.y + dpDy[i];
            int dpX = node.x + dpDx[i];
            if(dp[dpY][dpX] == -1 || dp[dpY][dpX] > nCost){
                dp[dpY][dpX] = nCost;
                pq.push(Node(dpY, dpX, nCost));
            }
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
        cin >> boards[i];
    }
    
    int result = solve();
    if(result == -1){
        cout << "NO SOLUTION\n";
    }
    else{
        cout << result << "\n";
    }
    return 0;
}
