#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, t;
typedef pair<int, int> PAIR;
vector<PAIR> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> t;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i].second >> v[i].first;
    }
    
    sort(v.begin(), v.end(), greater<PAIR>());
    
    
    long long result = 0;
    for(int i=0;i<n;i++){
        long long temp = t - 1 - i;
        temp *= v[i].first;
        temp += v[i].second;
        
        result += temp;
    }
    
    cout << result << "\n";
    
    return 0;
}

