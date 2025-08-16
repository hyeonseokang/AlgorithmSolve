#include<iostream>

using namespace std;

int t;

int dp[2001][2001] = {0};
const int MOD = 100999;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    dp[0][0] = 1;
    for(int i=1;i<=2000;i++){
        dp[i][0] = 0;
        dp[0][i] = 1;
    }
    
    for(int i=1;i<=2000;i++){
        for(int j=1;j<=2000;j++){
            dp[i][j] = dp[i][j-1];
            dp[i][j] %= MOD;
            if(i - j >= 0){
                dp[i][j] += dp[i-j][j-1];
                dp[i][j] %= MOD;
            }
        }
    }
    
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        cout << dp[n][n] << "\n";
    }
    
    return 0;
}
