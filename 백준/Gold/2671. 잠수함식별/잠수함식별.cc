#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string s;

int dp[150] = {0};
// (100~1~|01)~
bool Solve(const string& s, int i){
    if(i >= s.size())
        return true;
    
    if(dp[i] != -1)
        return dp[i];
    
    
    char c = s[i];
    
    bool isResult = false;
    if(c == '1') // 100~1~
    {
        if(i + 3 >= s.size())
            return dp[i] = false;
        if(s[i + 1] != '0' || s[i + 2] != '0')
            return dp[i] = false;
        int idx = i + 3;
        
        // 1000101
        while(idx < s.size() && s[idx] == '0')
            idx++;
        if(idx >= s.size())
            return dp[i] = false;
        idx++;
        while(idx < s.size() && s[idx] == '1'){
            if(Solve(s, idx))
                isResult = true;
            idx++;
        }
        if(Solve(s, idx))
            isResult = true;
    }
    else if(c == '0') // 01
    {
        if(i + 1 < s.size() && s[i + 1] == '1')
        {
            if(Solve(s, i + 2))
                isResult = true;
        }
    }
    
    return dp[i] = isResult;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    
    cin >> s;
    
    if(Solve(s, 0) == true){
        cout << "SUBMARINE\n";
    }
    else{
        cout << "NOISE\n";
    }
    
    return 0;
}
