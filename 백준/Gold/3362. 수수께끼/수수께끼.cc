#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t;
int n, k;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    while(t--){
        cin >> n >> k;
        
        vector<pair<int, int>> coins(n);
        for(int i=0;i<n;i++){
            cin >> coins[i].first;
            coins[i].second = i + 1;
        }
        
        sort(coins.begin(), coins.end());
        
        int l = 0, r = n;
        
        while(l <= r){
            int m = (l + r) / 2;
            
            int sumCoin = 0;
            bool isPossible = true;
                
            for(int i=0;i<n;i++){
                int coin = coins[i].first;
                int index = coins[i].second;
                
                if(index > m){
                    continue;
                }
                
                // 이러면 다 못만들어버림
                if(sumCoin + 1 < coin){
                    isPossible = false;
                    break;
                }
                
                sumCoin += coin;
                if(sumCoin >= k)
                    break;
            }
            
            if(sumCoin < k || !isPossible){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        
        int result = l;
        if(result == 0 || result > n)
            result = -1;
        cout << result << "\n";
    }
    
    return 0;
}
