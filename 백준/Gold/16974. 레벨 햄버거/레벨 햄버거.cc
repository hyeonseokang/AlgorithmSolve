#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

int N;
long long X;
long long patty[51] = {0};
long long burn[51] = {0};
long long burger[51] = {0};

long long solve(int n, long long x){
    if(n == 0 && x == 1)
        return 1;
    
    long long prevBurger = burger[n - 1];
    long long result = 0;
    if(x > 1 && x < prevBurger + 1){
        result += solve(n-1, x - 1);
    }
    if(x >= prevBurger + 1){
        result += patty[n-1];
    }
    if(x > prevBurger + 1){
        result ++; // 패티 한장 추가
    }
    if(prevBurger + 2 < x && x < prevBurger * 2 + 2){
        result += solve(n-1, x - prevBurger - 2);
    }
    if(x >= burger[n] - 1){
        result += patty[n-1];
    }
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> X;
    patty[0] = 1;
    burger[0] = 1;
    
    for(int i=1;i<=N;i++){
        patty[i] = patty[i-1] * 2 + 1;
        burn[i] = burn[i-1] * 2 + 2;
        burger[i] = patty[i] + burn[i];
    }
    
    cout << solve(N, X);
    
    return 0;
}
