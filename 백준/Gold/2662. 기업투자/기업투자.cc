#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
int investCompany[21][301];
int dp[21][301] = {0};
int backtrace[21][301] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        int cost;
        cin >> cost;
        for(int j=1;j<=m;j++){
            cin >> investCompany[j][cost];
        }
    }
    
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i-1][j];
            backtrace[i][j] = 0;
            for(int k=1;k<=j;k++){
                int temp = dp[i - 1][j - k] + investCompany[i][k];
                if(dp[i][j] <= temp){
                    dp[i][j] = temp;
                    backtrace[i][j] = k;
                }
            }
        }
    }
    
    cout << dp[m][n] << "\n";
    vector<int> trace(m + 1, 0);
    int currentInvest = n;
    for(int i=m;i>=1;i--){
        trace[i] = backtrace[i][currentInvest];
        currentInvest -= backtrace[i][currentInvest];
    }
    for(int i=1;i<=m;i++){
        cout << trace[i] << " ";
    }
    
    return 0;
}
