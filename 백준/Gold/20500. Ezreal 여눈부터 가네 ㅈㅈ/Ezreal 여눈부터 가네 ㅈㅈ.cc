#include<iostream>
#include<algorithm>
using namespace std;

int dp[1516] = {0};
constexpr int MOD = 1000000007;

int dpTen[1516] = {0};
int dpFive[1516] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    dpFive[1] = 1;
    dpTen[2] = 1;
    dp[2] = 1;
    
    int n;
    cin >> n;
    
    for(int i=3;i<=n;i++){
        // 1 선택시
        dp[i] += dpFive[i-1];
        dpFive[i] += dpTen[i-1];
        dpTen[i] += dp[i-1];
        
        // 5 선택시
        dp[i] += dpTen[i-1];
        dpFive[i] += dp[i-1];
        dpTen[i] += dpFive[i-1];
        
        dp[i] %= MOD;
        dpFive[i] %= MOD;
        dpTen[i] %= MOD;
    }
    
    cout << dp[n] << "\n";
}
