#include<iostream>
#include<cstring>
#include<algorithm>
#include<limits.h>

using namespace std;

int n, m;
int numbers[5000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> numbers[i];
    }
    
    int l = 0;
    int r = 20000;
    
    while(l < r){
        int mid = (l + r) / 2; // 구간 점수의 최댓값
        
        int minNum = INT_MAX;
        int maxNum = 0;
        int cnt = 0;
        for(int i= 0;i<n-1;i++){
            minNum = min(minNum, numbers[i]);
            maxNum = max(maxNum, numbers[i]);
            
            int temp = maxNum - minNum;
            if(temp > mid){
                minNum = numbers[i];
                maxNum = numbers[i];
                cnt++;
            }
        }
        
        minNum = min(minNum, numbers[n - 1]);
        maxNum = max(maxNum, numbers[n -1]);
        
        int temp = maxNum - minNum;
        if(temp > mid){
            cnt += 2;
        }
        else
            cnt++;
        
        
        if(cnt <= m){
            r = mid;
        }
        else{
            l = mid + 1;
        }
        
    }
    
    cout << (l + r) / 2 << "\n";
    
    return 0;
}
