#include<iostream>
#include<vector>
using namespace std;


int n;
vector<int> nums;

void Solve(){
    if(nums.size() <= 1){
        cout << "A\n";
        return;
    }
    if(nums.size() == 2){
        if(nums[0] == nums[1])
            cout << nums[0] << "\n";
        else
            cout << "A\n";
        
        return;
    }
    
    bool isEqualsAll = true;
    for(int i=1;i<n;i++){
        if(nums[1] != nums[i]){
            isEqualsAll = false;
            break;
        }
    }
    
    if(isEqualsAll){
        cout << nums[1] << "\n";
        return;
    }
    
    int x = nums[1] - nums[0];
    int y = nums[2] - nums[1];
    if(x == 0 || y == 0 || y % x != 0){
        cout << "B\n";
        return;
    }
    
    int a = y / x;
    int b = nums[1] - nums[0] * a;
    
    for(int i=2;i<n-1;i++){
        x = nums[i] - nums[i-1];
        y = nums[i+1] - nums[i];
        
        if(x == 0 || y == 0 || y % x != 0){
            cout << "B\n";
            return;
        }
        
        int tempA = y / x;
        int tempB = nums[i] - nums[i-1] * tempA;
        if(a != tempA || b != tempB){
            cout << "B\n";
            return;
        }
    }
    
    cout << nums.back() * a + b << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    nums.resize(n);
    
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    
    Solve();
    
    return 0;
}
