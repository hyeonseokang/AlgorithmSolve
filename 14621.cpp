#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
bool isMenUniversity[1001] = {false};
int parents[1001] = {0};

int Find(int x){
    int parent = parents[x];
    
    if(parent == x)
        return parent;
    
    return parents[parent] = Find(parent);
}

bool Merge(int a, int b){
    int aParent = Find(a);
    int bParent = Find(b);
    
    if(aParent == bParent)
        return false;
    else if(aParent < bParent)
        parents[bParent] = aParent;
    else
        parents[aParent] = bParent;
    
    return true;
}

struct Node{
    int s;
    int e;
    int dist;
    
    Node(int ns, int ne, int ndist):s(ns),e(ne),dist(ndist){
        
    }
    
    bool operator <(const Node& other) const{
        return dist < other.dist;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        parents[i] = i;
        
        char c;
        cin >> c;
        if(c == 'M')
            isMenUniversity[i] = true;
    }
    
    vector<Node> nodes;
    for(int j=0;j<m;j++){
        int s, e, dist;
        cin >> s >> e >> dist;
        
        nodes.emplace_back(s, e, dist);
    }
    
    sort(nodes.begin(), nodes.end());
    
    
    int result = 0;
    for(int i=0;i<nodes.size();i++){
        int s = nodes[i].s;
        int e = nodes[i].e;
        int dist = nodes[i].dist;
        
        if(isMenUniversity[s] == isMenUniversity[e])
            continue;
        
        bool isMergeSuccess = Merge(s, e);
        
        if(isMergeSuccess == true){
            result += dist;
        }
    }
    
    for(int i=1;i<=n;i++){
        int parent = Find(i);
        if(parent != 1){
            result = -1;
            break;
        }
    }
    
    
    cout << result << "\n";
    
    return 0;
}
