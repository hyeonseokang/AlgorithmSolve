#include<iostream>
#include<cstring>

using namespace std;

int n, k;

int dp[1000][1000] = {0};
constexpr int MOD = 1000000003;
int solve(int len, int currentK){
    if(currentK == 0)
        return 1;
    if(currentK == 1)
        return len;
    if(len < 2)
        return 0;
    
    int& ret = dp[len][currentK];
    if(ret != -1)
        return ret;
    
    ret = solve(len - 2, currentK - 1) + solve(len - 1, currentK);
    ret %= MOD;
    
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    
    int result = solve(n - 3, k -1) + solve(n - 1, k);
    result %= MOD;
    
    cout << result << "\n";
    return 0;
}
