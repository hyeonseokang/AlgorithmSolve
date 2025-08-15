#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

int n, k;
string result = "";
int dp[600][31][31][31];

int solve(int a, int b, int c, int k){
    if(k < 0)
        return 0;
    if(a == 0 && b == 0 && c == 0 && k == 0){
        dp[0][0][0][0] = 1;
        return 1;
    }
    
    
    
    int& ret = dp[k][a][b][c];
    if(ret != -1)
        return ret;
    
    ret = 0;
    if(a > 0)
        ret += solve(a-1, b, c, k - b - c);
    if(b > 0)
        ret += solve(a, b-1, c, k - c);
    if(c > 0)
        ret += solve(a, b, c-1, k);
    
    return ret;
}

void backtrace(int a, int b, int c, int k){
    if(a == 0 && b == 0 && c == 0 && k == 0)
        return;
    
    if(a > 0 && k - b - c >= 0 && dp[k-b-c][a-1][b][c] > 0){
        cout << 'A';
        backtrace(a-1, b, c, k - b - c);
    }
    else if(b > 0 && k - c >= 0 && dp[k-c][a][b-1][c] > 0){
        cout << 'B';
        backtrace(a, b-1, c, k - c);
    }
    else if(c > 0 && dp[k][a][b][c-1] > 0){
        cout << 'C';
        backtrace(a, b, c-1, k);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    result = string(n, ' ');
    memset(dp, -1, sizeof(dp));
    
    bool isEnd = false;
    for(int a=0;a<=n;a++){
        if(isEnd) break;
        for(int b=0;b<=n-a;b++){
            if(isEnd) break;
            int c = n - a - b;
            
            if(solve(a, b, c, k) > 0){
                backtrace(a, b, c, k);
                isEnd = true;
            }
        }
    }
    
    if(!isEnd){
        cout << "-1\n";
    }
    return 0;
}
