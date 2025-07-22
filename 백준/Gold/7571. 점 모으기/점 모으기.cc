#include<iostream>
#include<algorithm>
#include<limits.h>

using namespace std;

int xPrefixSum[10002] = {0};
int yPrefixSum[10002] = {0};
int xCntSum[10002] = {0};
int yCntSum[10002] = {0};

int xPrefixSumReverse[10002] = {0};
int yPrefixSumReverse[10002] = {0};

int numbersY[10001] = {0};
int numbersX[10001] = {0};
int n, m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int y, x;
        cin >> y >> x;
        
        numbersY[y] += y;
        numbersX[x] += x;
        yCntSum[y] ++;
        xCntSum[x] ++;
    }
    
    for(int i=1;i<=n;i++){
        yPrefixSum[i] = yPrefixSum[i - 1] + numbersY[i];
        xPrefixSum[i] = xPrefixSum[i - 1] + numbersX[i];
        yCntSum[i] += yCntSum[i - 1];
        xCntSum[i] += xCntSum[i - 1];
    }
    for(int i=n;i>=0;i--){
        yPrefixSumReverse[i] = yPrefixSumReverse[i + 1] + numbersY[i];
        xPrefixSumReverse[i] = xPrefixSumReverse[i + 1] + numbersX[i];
    }
    
    int xMin = INT_MAX;
    int yMin = INT_MAX;
    for(int i=1;i<=n;i++){
        int yCnt = yCntSum[i];
        int xCnt = xCntSum[i];
        
        int y = yPrefixSumReverse[i + 1] - yPrefixSum[i];
        int x = xPrefixSumReverse[i + 1] - xPrefixSum[i];
        
        y = y + (i * yCnt) - (i * (m - yCnt));
        x = x + (i * xCnt) - (i * (m - xCnt));
        
        yMin = min(yMin, y);
        xMin = min(xMin, x);
    }
    
    cout << yMin + xMin << "\n";
    
    return 0;
}
