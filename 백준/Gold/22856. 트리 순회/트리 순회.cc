#include<iostream>
#include<vector>

using namespace std;

int n;

struct Node{
    int left;
    int right;
};

vector<Node> nodes;
int e;
int result = 0;

void InOrder(int s){
    if(s == -1)
        return;
    
    InOrder(nodes[s].left);
    
    e = s;
    InOrder(nodes[s].right);
}

bool solve(int s){
    int left = nodes[s].left;
    int right = nodes[s].right;
    
    if(left != -1){
        result++;
        if(!solve(left)){
            return false;
        }
        result++;
    }
    if(right != -1){
        result++;
        if(!solve(right)){
            return false;
        }
        result++;
    }
    
    if(e == s)
        return false;
    
    
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    nodes.resize(n + 1);
    for(int i=1;i<=n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].left = b;
        nodes[a].right = c;
    }
    e = 1;
    InOrder(1);
    
    solve(1);
    cout << result << "\n";
    
    return 0;
}
