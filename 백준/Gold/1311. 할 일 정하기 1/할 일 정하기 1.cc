#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

#define COST 10000
#define MAX_COST(X) X*COST
typedef pair<int, int> PAIR;

int n;
vector<vector<PAIR>> costs;
int workMinCost[20] = {0};
unordered_map<int, int> dp;

int solve(int len,int bit){
    if(len == n){
        return 0;
    }
    if(dp.find(bit) != dp.end())
        return dp[bit];
    
    int& result = dp[bit] = INT_MAX;
    
    
    vector<PAIR>& works = costs[len];
    for(int i=0;i<works.size();i++){
        const PAIR& p = works[i];
        if((bit & (1 << p.second))) continue;
        int next = (bit | (1 << p.second));
        result = min(result, solve(len + 1, next) + p.first);
    }
    
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i=0;i<n;i++){
        workMinCost[i] = INT_MAX;
    }
    costs.resize(n);
    for(int i=0;i<n;i++){
        costs[i].resize(n);
        for(int j=0;j<n;j++){
            cin >> costs[i][j].first;
            costs[i][j].second = j;
            workMinCost[j] = min(workMinCost[j], costs[i][j].first);
        }
        
        sort(costs[i].begin(), costs[i].end());
    }
    
    cout << solve(0, 0) << "\n";
    
    return 0;
}
