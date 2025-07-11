#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

constexpr int HEXA_SIZE = 708;
int hexagon[HEXA_SIZE] = {0};

int n;
int dp[1000001] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    hexagon[0] = 1;
    
    for(int i=1;i<HEXA_SIZE;i++){
        hexagon[i] = hexagon[i-1] + 4 * i + 1;
    }
    
    cin >> n;
    
    int currentHexa = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = INT_MAX;
        if(hexagon[currentHexa] == i){
            dp[i] = 1;
            currentHexa++;
        }
        for(int j=0;j<currentHexa;j++){
            int hexaIdx = hexagon[j];
            dp[i] = min(dp[i], dp[hexaIdx] + dp[i- hexaIdx]);
        }
    }
    
    cout << dp[n] << "\n";
    
    return 0;
}
