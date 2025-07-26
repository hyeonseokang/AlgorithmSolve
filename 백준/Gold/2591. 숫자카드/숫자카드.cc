#include<iostream>
#include<string>
#include<cstring>

using namespace std;

string s;

long long dp[40] = {0};

long long solve(int len){
    if(s.size() == len){
        return 1;
    }
    
    if(s[len] == '0')
        return 0;
    
    long long& result = dp[len];
    if(dp[len] != -1)
        return result;
    result = 0;
    char c = s[len];
    
    // 4 미만이면
    if(c < '4' && s.size() > len + 1){
        char nextC = s[len + 1];
        
        if(c == '3' && nextC > '4'){}
        else{
            result += solve(len + 2);
        }
    }
    
    result += solve(len + 1);
    
    
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(dp, -1, sizeof(dp));
    
    cin >> s;
    long long result = solve(0);
    
    cout << result << "\n";
    
    return 0;
}
