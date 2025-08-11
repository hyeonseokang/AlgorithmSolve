#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int n;
int costs[20][20] = {0};
vector<int> dp;


int solve(int len,int bit){
    if(len == n){
        return 0;
    }
    if(dp[bit] != -1)
        return dp[bit];
    
    int& result = dp[bit] = INT_MAX;
    
    
    for(int i=0;i<n;i++){
        if((bit & (1 << i))) continue;
        int next = (bit | (1 << i));
        result = min(result, solve(len + 1, next) + costs[len][i]);
    }
    
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    dp.resize(1 << n, -1);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> costs[i][j];
        }
    }
    
    cout << solve(0, 0) << "\n";
    
    return 0;
}
