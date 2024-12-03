#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

int n, m;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int dp[12][12][12][12];

struct Node{
    int y;
    int x;
    Node(){}
    Node(int _y, int _x):x(_x), y(_y){
    }
};

struct QueueNode{
    Node red;
    Node blue;
    int count = 0;
    
    QueueNode(const Node& _red, const Node& _blue, int _count):red(_red), blue(_blue), count(_count){}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    vector<vector<char>> map(n + 2, vector<char>(m + 2, '#'));
    memset(dp, -1, sizeof(dp));
    Node red, blue;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        for(int j=1;j<=m;j++){
            map[i][j] = s[j-1];
            if(map[i][j] == 'B')
                blue = Node(i, j);
            else if(map[i][j] == 'R')
                red = Node(i, j);
        }
    }
    
    queue<QueueNode> q;
    q.push(QueueNode(red, blue, 0));
    dp[red.y][red.x][blue.y][blue.x] = 0;
    int result = -1;
    while(!q.empty()){
        QueueNode qn = q.front();
        q.pop();
        if(qn.count >= 10){
            break;
        }
        for(int i=0;i<4;i++){
            int ry = qn.red.y, rx = qn.red.x;
            int by = qn.blue.y, bx = qn.blue.x;
            
            bool isRedHole = false;
            bool isBlueHole = false;
            int blueDistance = 0;
            int redDistance = 0;
            while(map[ry][rx] != '#' && map[ry][rx] != 'O'){
                ry += dy[i];
                rx += dx[i];
                redDistance++;
            }
            while(map[by][bx] != '#' && map[by][bx] != 'O'){
                by += dy[i];
                bx += dx[i];
                blueDistance++;
            }
            if(map[ry][rx] == 'O')
                isRedHole = true;
            if(map[by][bx] == 'O')
                continue;
            
            if(ry == by && rx == bx){
                if(redDistance > blueDistance){
                    ry -= (dy[i] + dy[i]);
                    rx -= (dx[i] + dx[i]);
                    by -= dy[i];
                    bx -= dx[i];
                }
                else{
                    ry -= dy[i];
                    rx -= dx[i];
                    by -= (dy[i] + dy[i]);
                    bx -= (dx[i] + dx[i]);
                }
            }
            else{
                ry -= dy[i];
                rx -= dx[i];
                by -= dy[i];
                bx -= dx[i];
            }
            
            if(isBlueHole == true){
                continue;
            }
            else if(isRedHole == true){
                result = qn.count + 1;
                while(!q.empty()){
                    q.pop();
                }
                break;
            }
            
            if(dp[ry][rx][by][bx] == -1){
                dp[ry][rx][by][bx] = qn.count + 1;
                q.push(QueueNode(Node(ry, rx), Node(by, bx), qn.count + 1));
            }
        }
    }
    
    cout << result << "\n";
    return 0;
}
