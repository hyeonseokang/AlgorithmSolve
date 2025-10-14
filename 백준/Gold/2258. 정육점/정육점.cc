#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>

using namespace std;

int n, m;
vector<pair<int, int>> meats;

bool Compare(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    
    // 가격이 같으면 무게가 큰 순서대로
    return a.second > b.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    meats.resize(n);
    for(int i=0;i<n;i++){
        cin >> meats[i].second >> meats[i].first; // 무게, 가격
    }
    
    sort(meats.begin(), meats.end(), Compare);
    vector<pair<int, int>> sums; // sums, cost;
    
    int currentCost = -1;
    int prevSums = 0;
    int prevCostSums = 0;
    for(int i=0;i<n;i++){
        int cost = meats[i].first;
        int weight = meats[i].second;
        
        prevSums += weight;
        if(currentCost != cost){
            currentCost = cost;
            prevCostSums = cost;
            sums.emplace_back(cost, prevSums);
        }
        else{ // 비용이 같음
            prevCostSums += cost;
            sums.emplace_back(prevCostSums, prevSums);
        }
    }
    
    long long result = (long long)INT_MAX + 1;
    for(int i=0;i<sums.size();i++){
        if(sums[i].second >= m){
            result = min(result, (long long)sums[i].first);
        }
    }
    
    if(result > INT_MAX)
        result = -1;
    
    cout << result << "\n";
    
    return 0;
}