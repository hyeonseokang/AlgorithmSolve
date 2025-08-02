#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int n;
string nodeColors;
vector<vector<int>> tree;
vector<bool> visited;

namespace State{
constexpr int InSide = 0;
constexpr int OutSide = 1;
}

bool IsInSide(int node){
    return nodeColors[node] == '1'?true:false;
}

int Solve(int s){
    
    int result = 0;
    vector<int>& nodes = tree[s];
    
    int insideCount = 0;
    if(IsInSide(s)){
        for(int i=0;i<nodes.size();i++){
            int e = nodes[i];
            if(visited[e] == true) continue;
            
            if(IsInSide(e)){
                insideCount++;
            }
            visited[e] = true;
            result += Solve(e);
        }
        result += (insideCount * 2);
    }
    else{
        for(int i=0;i<nodes.size();i++){
            int e = nodes[i];
            if(visited[e] == true) continue;
            
            if(IsInSide(e)){
                insideCount++;
            }
            visited[e] = true;
            result += Solve(e);
        }
        if(insideCount > 0)
            result += (insideCount * (insideCount + 1));
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    cin >> nodeColors;
    nodeColors = "0" + nodeColors;
    tree.resize(n + 1);
    visited.resize(n + 1, false);
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    
    visited[1] = true;
    cout << Solve(1);
    return 0;
}
