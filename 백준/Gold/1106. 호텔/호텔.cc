#include<iostream>
#include<algorithm>
#include<limits.h>

using namespace std;

int c, n;

struct City{
    int cost;
    int value;
    
    City(int InCost, int InValue):cost(InCost),value(InValue){
        
    }
    
    City(){
        
    }
};

City cities[21];
int dp[21][1001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> c >> n;
    
    for(int i=1;i<=n;i++){
        cin >> cities[i].cost >> cities[i].value;
    }
    
    for(int j=0;j<=c;j++){
        dp[0][j] = INT_MAX;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=c;j++){
            int temp = cities[i].cost;
            if(j - cities[i].value > 0){
                temp += dp[i][j-cities[i].value];
            }
            
            
            dp[i][j] = min(temp, dp[i-1][j]);
        }
    }
    
    cout << dp[n][c] << "\n";
    
    return 0;
}
