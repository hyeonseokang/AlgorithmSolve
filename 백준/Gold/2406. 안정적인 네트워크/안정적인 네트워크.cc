#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
int parents[1001] = {0};
int costs[1001][1001] = {0};
typedef pair<int, pair<int, int>> PAIR;
priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;

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
    
    if(aParent < bParent){
        parents[bParent] = aParent;
    }
    else{
        parents[aParent] = bParent;
    }
    
    return true;
}

void solve(){
    int sumCost = 0;
    vector<pair<int, int>> newAddedPair;
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();
        
        if(Merge(a, b)){
            sumCost += cost;
            newAddedPair.emplace_back(a, b);
        }
    }
    
    cout << sumCost << " " << newAddedPair.size() << "\n";
    for(int i=0;i<newAddedPair.size();i++){
        cout << newAddedPair[i].first << " " << newAddedPair[i].second << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0;i<=n;i++){
        parents[i] = i;
    }
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        Merge(a, b);
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> costs[i][j];
        }
    }
    
    for(int i=2;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int cost = costs[i][j];
            pq.push({cost, {i, j}});
        }
    }
    
    solve();
    
    return 0;
}