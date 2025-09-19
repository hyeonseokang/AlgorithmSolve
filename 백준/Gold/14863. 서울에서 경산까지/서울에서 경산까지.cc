#include<iostream>
#include<algorithm>

using namespace std;

int n, k;
int dp[101][100001] = {0};
int startTimes[101] = {0};
pair<int, int> p[101][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> p[i][0].first >> p[i][0].second >> p[i][1].first >> p[i][1].second;
        
        startTimes[i] = startTimes[i-1] + min(p[i-1][0].first, p[i-1][1].first);
    }
    
    for(int i=1;i<=n;i++){
        int startTime = startTimes[i];
        for(int j=1;j<=k;j++){
            for(int t=0;t<2;t++){
                int cost = p[i][t].first;
                int value = p[i][t].second;
                
                int prevCost = j - cost;
                if(prevCost < startTime)  continue;
                
                dp[i][j] = max(dp[i][j], dp[i-1][prevCost] + value);
            }
        }
    }
    
    cout << dp[n][k] << "\n";
    
    
    return 0;
}
