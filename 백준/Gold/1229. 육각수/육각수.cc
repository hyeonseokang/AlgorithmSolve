#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

constexpr int HEXA_SIZE = 708;
int HEXA_CNT = 0;
int hexagon[HEXA_SIZE] = {0};

int n;
int dp[1000001] = {0};

bool solve(int num, int cnt, int maxCnt){
    if(num == 0 && cnt == maxCnt)
        return true;
    else if(num <= 0 || cnt >= maxCnt)
        return false;
    
    for(int i=0;i<HEXA_CNT;i++){
        int hexaNum = hexagon[i];
        
        if(num < hexaNum)
            break;
        
        if(solve(num - hexaNum, cnt + 1, maxCnt))
            return true;
    }
    
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    hexagon[0] = 1;
    HEXA_CNT = 1;
    
    for(int i=1;i<HEXA_SIZE;i++){
        hexagon[i] = hexagon[i-1] + 4 * i + 1;
        if(hexagon[i] > n) break;
        HEXA_CNT++;
    }
    
    
    int m = 6;
    
    for(int i=1;i<=m;i++){
        if(solve(n, 0, i)){
            cout << i << "\n";
            break;
        }
    }
    
    return 0;
}
