#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<int, long long>> town;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    town.resize(n);
    
    long long sumCnt = 0;
    for(int i=0;i<n;i++){
        cin >> town[i].first >> town[i].second;
        sumCnt += town[i].second;
    }
    
    sort(town.begin(), town.end());
    long long mid = sumCnt / 2;
    if(sumCnt % 2 == 1){
        mid = (sumCnt +1)/ 2;
    }
    
    long long prefixSums = 0;
    for(int i=0;i<n;i++){
        int pos = town[i].first;
        long long people = town[i].second;
        
        prefixSums += people;
        
        if(prefixSums >= mid){
            cout << pos << "\n";
            break;
        }
    }
    
    return 0;
}