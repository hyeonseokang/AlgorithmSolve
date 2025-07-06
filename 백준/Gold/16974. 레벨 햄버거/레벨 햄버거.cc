#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

int N;
long long X;
long long burgerIngredientCnts[51] = {0};
unordered_map<long long, long long> dp[51];
// 2, 7
// B BPPPB P BPPPB B
// B P P P B
long long solve(int n, long long x){
    if(n == 0 && x == 1)
        return 1;
    
    if(dp[n].find(x) != dp[n].end())
        return dp[n][x];
    
    long long prevLevelIngredientCnt = burgerIngredientCnts[n - 1];
    long long result = 0;
    if(x > 1){
        result += solve(n-1, min(x-1,
                                 prevLevelIngredientCnt));
    }
    if(x > prevLevelIngredientCnt + 1){
        result ++; // 패티 한장 추가
    }
    if(x > prevLevelIngredientCnt + 2){
        result += solve(n-1, min(x - prevLevelIngredientCnt - 2,
                                 prevLevelIngredientCnt));
    }
    dp[n][x] = result;
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> X;
    
    burgerIngredientCnts[0] = 1;
    for(int i=1;i<=N;i++){
        burgerIngredientCnts[i] = burgerIngredientCnts[i-1] * 2 + 3;
    }
    
    cout << solve(N, X);
    
    return 0;
}
