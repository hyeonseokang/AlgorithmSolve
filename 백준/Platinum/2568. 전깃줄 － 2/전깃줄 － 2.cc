#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;
vector<int> result;
vector<pair<int,int>> v;

void backtrace(int size, int index){
    if(index < 0)
        return;
    
    if(result[index] == size){
        backtrace(size-1, index-1);
    }
    else{
        backtrace(size, index-1);
        cout << v[index].first << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++){
        int s, e;
        cin >> s >> e;
        v[i] = {s, e};
    }
    
    sort(v.begin(), v.end());
    
    vector<int> lis;
    lis.reserve(n);
    result.resize(n);
    
    for(int i=0;i<n;i++){
        auto it = lower_bound(lis.begin(), lis.end(), v[i].second);
        
        if(it == lis.end()){
            lis.emplace_back(v[i].second);
            result[i] = lis.size() - 1;
        }
        else{
            *it = v[i].second;
            result[i] = (it - lis.begin());
        }
    }
    
    cout << n - lis.size() << "\n";
    backtrace(lis.size()-1, n-1);
    return 0;
}
