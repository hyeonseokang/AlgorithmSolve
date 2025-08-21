#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

int l,k,c;
unordered_set<int> us;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> l >> k >> c;
    for(int i=0;i<k;i++){
        int num;
        cin >> num;
        us.insert(num);
    }
    
    vector<int> numbers(us.begin(), us.end());
    sort(numbers.begin(), numbers.end());
    numbers.emplace_back(l);
    
    int left = 1;
    int right = l;
    int cutMinIndex = -1;
    
    while(left < right){
        int m = (left + right) / 2;
        
        int prev = l;
        int cutCnt = 0;
        
        for(int i=numbers.size()-2;i>=0;i--){
            if(numbers[i + 1] - numbers[i] > m){
                cutCnt = c;
                break;
            }
            int len = prev - numbers[i];
            
            if(m < len){
                cutCnt++;
                prev = numbers[i + 1];
                if(cutCnt >= c) break;
            }
        }
        
        if(cutCnt < c){
            prev = numbers[0];
        }
        
        if(prev > m){
            left = m + 1;
        }
        else{
            right = m;
            cutMinIndex = prev;
        }
    }
    
    cout << right << " " << cutMinIndex << "\n";
    
    return 0;
}
