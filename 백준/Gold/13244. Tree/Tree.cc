#include<iostream>
#include<cstring>

using namespace std;

int t, n, m;
int map[1001][1001] = {0};
bool isVisited[1001] = {false};

bool DFS(int s, int parent){
    isVisited[s] = true;
    for(int i=1;i<=n;i++){
        if(i == parent || i == s) continue;
        if(map[s][i] == 0) continue;
        
        if(isVisited[i] == true)
            return false;
        if(!DFS(i, s)){
            return false;
        }
    }
    
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    while(t--){
        memset(map, 0, sizeof(map));
        memset(isVisited, false, sizeof(isVisited));
        
        cin >> n;
        cin >> m;
        
        bool isTree = true;
        for(int i=0;i<m;i++)
        {
            int a, b;
            cin >> a >> b;
            if(map[a][b] == 1 || map[b][a] == 1)
                isTree = false;
            
            map[a][b] = 1;
            map[b][a] = 1;
        }
        
        if(isTree == true && !DFS(1, 0)){
            isTree = false;
        }
        
        for(int i=1;i<=n;i++){
            if(isVisited[i] == false){
                isTree = false;
                break;
            }
        }
        
        if(isTree)
            cout << "tree\n";
        else
            cout << "graph\n";
    }
    
    return 0;
}
