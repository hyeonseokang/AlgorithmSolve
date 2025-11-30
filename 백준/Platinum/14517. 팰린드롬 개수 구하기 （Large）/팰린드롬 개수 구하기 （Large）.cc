#include<iostream>
#include<cstring>
#include<string>

using namespace std;

const int MOD = 10007;
int dp[1000][1000] = {0};
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    for(int i=0;i<s.size();i++){
        dp[i][i] = 1;
    }
    
    for(int len = 2;len <= s.size();len++){
        for(int r=len - 1;r<s.size();r++){
            int l = r - len + 1;
            if(s[l] == s[r]){
                dp[l][r] = dp[l+1][r-1] + 1;
            }
            
            dp[l][r] += dp[l + 1][r] + dp[l][r-1] - dp[l + 1][r - 1] + MOD;
            dp[l][r] %= MOD;
        }
    }
    
    cout << dp[0][s.size()-1] << "\n";
    
    return 0;
}

// abcda

// a b c d a
// ab, ac, ad, aa, bc, bd, ba, cd, ca
// abc, abd, aba, acd, aca, ada, bcd, bca, bda, cda
// abcd, abca, acda, bcda
// abcda


