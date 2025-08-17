#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<double, int>> v;
    v.resize(n);
    for(int i=0;i<n;i++){
        int t, s;
        cin >> t >> s;
        v[i] = make_pair((double)t/(double)s,i);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0;i<n;i++){
        cout << v[i].second + 1 << " ";
    }
    
    return 0;
}
