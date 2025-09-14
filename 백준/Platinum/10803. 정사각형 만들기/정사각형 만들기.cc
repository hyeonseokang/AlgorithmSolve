#include<iostream>
#include<algorithm>
#include<cstring>
#include<limits.h>
using namespace std;

int dp[10001][101] = {0};
int n, m;

int solve(int h, int w){
    if(h == 0 || w == 0)
        return 0;
    
    int& ret = dp[h][w];
    if(ret != -1)
        return ret;
    ret = INT_MAX;
    
    if(h == w)
        return ret = 1;
    else if(h > w){
        if(h % w == 0){
            return ret = h/w;
        }
        
        if(h >= w*3){
            ret = min(ret, solve(h - w, w) + 1);
        }
        else{
            for(int i=1;i<=h/2;i++){
                ret = min(ret, solve(i, w) + solve(h - i, w));
            }
            for(int i=1;i<=w/2;i++){
                ret = min(ret, solve(h, i) + solve(h, w - i));
            }
        }
    }
    else{
        if(w % h == 0){
            return ret = w/h;
        }
        
        if(w >= h*3)
            ret = min(ret, solve(h, w-h) + 1);
        else{
            for(int i=1;i<=h/2;i++){
                ret = min(ret, solve(i, w) + solve(h - i, w));
            }
            for(int i=1;i<=w/2;i++){
                ret = min(ret, solve(h, i) + solve(h, w - i));
            }
        }
    }
    
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    
    for(int i=1;i<=100;i++){
        dp[i][i] = 1;
        dp[1][i] = i;
    }
    for(int i=1;i<=10000;i++){
        dp[i][1] = i;
    }
    
    cin >> n >> m;
    
    cout << solve(n, m) << "\n";
    
    return 0;
}
