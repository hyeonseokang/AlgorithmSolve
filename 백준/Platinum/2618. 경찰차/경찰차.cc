#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;

int n, w;
vector<pair<int, int>> policeCases;
int dp[1001][1001];
int selectDp[1001][1001];

int GetDist(int a, int b, int policeType){
    int aY = policeCases[a].first;
    int aX = policeCases[a].second;
    if(a == 0){
        if(policeType == 1){
            aY = 1;
            aX = 1;
        }
        else if(policeType == 2){
            aY = n;
            aX = n;
        }
    }
    
    return abs(aY - policeCases[b].first)
    + abs(aX - policeCases[b].second);
}

int solve(int lastA, int lastB){
    if(lastA == w || lastB == w)
        return 0;
    
    int& ret = dp[lastA][lastB];
    if(ret != -1)
        return ret;
    
    int next = max(lastA, lastB) + 1;
    
    int aMoveDist = solve(next, lastB) + GetDist(lastA, next, 1);
    int bMoveDist = solve(lastA, next) + GetDist(lastB, next, 2);
    
    if(aMoveDist < bMoveDist){
        ret = aMoveDist;
        selectDp[lastA][lastB] = 1;
    }
    else{
        ret = bMoveDist;
    }
    
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(dp, -1, sizeof(dp));
    
    cin >> n;
    cin >> w;
    policeCases.resize(w + 1);
    policeCases[0] = make_pair(0, 0);
    for(int i=1;i<=w;i++){
        cin >> policeCases[i].first >> policeCases[i].second;
    }
    
    cout << solve(0, 0) << "\n";
    
    int a = 0, b = 0;
    for(int i=1;i<=w;i++){
        if(selectDp[a][b] == 1){
            cout << "1\n";
            a = i;
        }
        else{
            cout << "2\n";
            b = i;
        }
    }
    
    return 0;
}
