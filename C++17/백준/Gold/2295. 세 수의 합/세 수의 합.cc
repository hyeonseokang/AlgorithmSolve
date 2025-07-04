#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int numbers[1000];
vector<int> pairNumbers;

// 5억? * logn

int solve(){
    for(int i=n-1;i>=0;i--){
        for(int j=i;j>=0;j--){
            int target = numbers[i] - numbers[j];
            
            auto it = lower_bound(pairNumbers.begin(), pairNumbers.end(), target);
            if(it == pairNumbers.end() || *it != target) // target 번호랑 같은걸 찾아야 하니까
                continue;
            
            int itIdx = it - pairNumbers.begin();
            return i;
        }
    }
    
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> numbers[i];
    }
    
    sort(numbers, numbers + n);
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int num = numbers[i] + numbers[j];
            pairNumbers.emplace_back(num);
        }
    }
    sort(pairNumbers.begin(), pairNumbers.end());
    
    int idx = solve();
    cout << numbers[idx] << "\n";
    
    return 0;
}
