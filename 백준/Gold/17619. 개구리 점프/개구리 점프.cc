#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, q;
vector<pair<pair<int, int>, int>> v;
vector<int> groupNumbers;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q;
    v.resize(n);
    groupNumbers.resize(n + 1);
    for(int i=0;i<n;i++){
        int y;
        cin >> v[i].first.first >> v[i].first.second >> y;
        
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
    
    int cnt = 0;
    int maxE = -1;
    for(int i=0;i<n;i++){
        int s = v[i].first.first;
        int e = v[i].first.second;
        int num = v[i].second;
        
        if(s <= maxE){
            maxE = max(maxE, e);
        }
        else{
            cnt++;
            maxE = e;
        }
        
        groupNumbers[num] = cnt;
    }
    
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        
        if(groupNumbers[a] == groupNumbers[b])
            cout << "1\n";
        else
            cout << "0\n";
    }
    
    
    
    return 0;
}
