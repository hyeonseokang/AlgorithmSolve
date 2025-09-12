#include<iostream>
#include<algorithm>
#include<cmath>
#include<limits.h>

using namespace std;

int n, k;
pair<int, int> positions[500];

int dists[500][500];
int dp[500][501] = {0};

int GetDistance(const pair<int, int>& a, const pair<int, int>& b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> positions[i].first >> positions[i].second;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            dists[i][j] = GetDistance(positions[i], positions[j]);
        }
    }
    
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0] + dists[i-1][i];
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j] = INT_MAX;
            for(int p=1;;p++){
                if(i - p < 0 || j - p + 1 < 0) break;
                dp[i][j] = min(dp[i][j], dp[i-p][j - p + 1] + dists[i-p][i]);
            }
        }
    }
    
    
    cout << dp[n-1][k] << "\n";
    
    return 0;
}
