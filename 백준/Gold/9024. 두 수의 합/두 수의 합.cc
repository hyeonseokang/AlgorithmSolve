#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<cmath>

using namespace std;

int t;
int n, k;
vector<int> numbers;

int GetSizeNum(int num){
    auto lowerIt = lower_bound(numbers.begin(), numbers.end(), num);
    auto upperIt = upper_bound(numbers.begin(), numbers.end(), num);
    
    if(lowerIt == numbers.end() || *lowerIt != num)
        return 0;
    
    return upperIt - lowerIt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    while(t--){
        cin >> n >> k;
        numbers.resize(n);
        
        for(int i=0;i<n;i++){
            cin >> numbers[i];
        }
        
        sort(numbers.begin(), numbers.end());
        
        int l = 0;
        int r = n - 1;
        
        int lCnt = GetSizeNum(numbers[l]);
        int rCnt = GetSizeNum(numbers[r]);
        
        int minDiff = INT_MAX;
        int result = 0;
        
        while(l < r){
            int num = numbers[l] + numbers[r];
            int diff = k - num;
            int absDiff = abs(diff);
            
            if(minDiff == absDiff){
                result += lCnt * rCnt;
            }
            else if(absDiff < minDiff){
                minDiff = absDiff;
                result = lCnt * rCnt;
            }
            
            
            if(diff >= 0){
                l += lCnt;
                if(l >= r)
                    break;
                lCnt = GetSizeNum(numbers[l]);
            }
            if(diff <= 0){
                r -= rCnt;
                if(r <= l)
                    break;
                rCnt = GetSizeNum(numbers[r]);
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}
