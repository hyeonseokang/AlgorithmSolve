#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int n;
vector<vector<int>> subwayMap;
bool visited[3001] = {false};
bool isCycle[3001] = {false};
vector<int> results;

int DFS(int s, int parent){
    const vector<int>& lines = subwayMap[s];
    
    for(int i=0;i<lines.size();i++){
        int e = lines[i];
        if(parent == e)
            continue;
        
        // 사이클 발생
        if(visited[e] == true){
            isCycle[s] = true;
            return e;
        }
        
        visited[e] = true;
        int temp = DFS(e, s);
        if(temp == s){
            isCycle[e] = true;
            isCycle[s] = true;
            return -1;
        }
        if(temp != -1){
            isCycle[e] = true;
            return temp;
        }
    }
    
    return -1;
}

void CalculateResult(int s, int cycleDepth){
    const vector<int>& lines = subwayMap[s];
    visited[s] = true;
    
    for(int i=0;i<lines.size();i++){
        int e = lines[i];
        if(visited[e] == true) continue;
        
        if(isCycle[e] == false){
            results[e] = cycleDepth + 1;
        }
        else{
            results[e] = cycleDepth;
        }
        
        CalculateResult(e, results[e]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    subwayMap.resize(n + 1);
    results.resize(n + 1);
    
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        
        subwayMap[a].emplace_back(b);
        subwayMap[b].emplace_back(a);
    }
    
    DFS(1, 0);
    for(int i=1;i<=n;i++){
        if(isCycle[i] == true){
            memset(visited, false, sizeof(visited));
            CalculateResult(i, 0);
            break;
        }
    }
    
    for(int i=1;i<=n;i++){
        cout << results[i] << " ";
    }
    
    return 0;
}
