#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> edges;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    long long result = 0;
    edges.resize(n);
    for(int i=0;i<n;i++){
        cin >> edges[i].second >> edges[i].first;
    }
    
    sort(edges.begin(), edges.end());
    
    int currentS = -1;
    int currentE = -1;
    for(int i=0;i<n;i++){
        int s = edges[i].second;
        int e = edges[i].first;
        
        if(s <= e) continue;
        
        if(currentS > e){
            currentS = max(currentS, s);
        }
        else{
            result += (currentS - currentE) * 2;
            currentS = s;
            currentE = e;
        }
    }
    
    result += (currentS - currentE) * 2;
    result += m;
    
    
    cout << result << "\n";
    
    return 0;
}
