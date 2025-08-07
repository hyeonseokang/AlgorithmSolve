#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int n, m, x;
vector<vector<int>> inGraph;
vector<vector<int>> outGraph;
bool visited[100001] = {false};

int DFS(const vector<vector<int>>& graph, int s){
    const vector<int>& nodes = graph[s];
    if(nodes.size() == 0)
        return 0;
    
    int result = 0;
    
    for(int i=0;i<nodes.size();i++){
        int e = nodes[i];
        if(visited[e] == true)
            continue;
        
        visited[e] = true;
        result += DFS(graph, e) + 1;
    }
    
    
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> x;
    inGraph.resize(n + 1);
    outGraph.resize(n + 1);
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        
        inGraph[a].emplace_back(b);
        outGraph[b].emplace_back(a);
    }
    memset(visited, false, sizeof(visited));
    int numLower = DFS(inGraph, x);
    memset(visited, false, sizeof(visited));
    int numHigher = DFS(outGraph, x);
    
    cout << numHigher + 1 << " " << n - numLower << "\n";
    
    return 0;
}
