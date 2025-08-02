#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int n;
string nodeColors;
vector<vector<int>> tree;
bool visited[200001] = {false};
int result = 0;


bool IsInSide(int node){
    return nodeColors[node] == '1'?true:false;
}

int Solve(int s){
    vector<int>& nodes = tree[s];
    
    int insideCount = 0;
    
    for(int i=0;i<nodes.size();i++){
        int e = nodes[i];
        
        if(IsInSide(e)){
            insideCount++;
        }
        else if(visited[e] == true){
            continue;
        }
        else{
            visited[e] = true;
            insideCount += Solve(e);
        }
    }
    
    return insideCount;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    cin >> nodeColors;
    nodeColors = "0" + nodeColors;
    tree.resize(n + 1);
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        
        bool isInsideA = IsInSide(a);
        bool isInsideB = IsInSide(b);
        
        if(isInsideA && isInsideB){
            result += 2;
            continue;
        }
        
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    
    for(int i=1;i<=n;i++){
        if(!IsInSide(i) && visited[i] == false){
            visited[i] = true;
            int insideCount = Solve(i);
            if(insideCount > 0)
                result += (insideCount * (insideCount - 1));
        }
    }
    
    cout << result << "\n";
    return 0;
}
