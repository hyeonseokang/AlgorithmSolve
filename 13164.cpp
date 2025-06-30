#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    for(int i=0;i<n;i++){
        cin >> heights[i];
    }
    
    vector<int> heightDiff(n-1);
    for(int i=0;i<n-1;i++){
        int height;
        cin >> height;
        heightDiff[i] = heights[i+1] - heights[i];
    }
    
    
    sort(heightDiff.begin(), heightDiff.end());
    int result = 0;
    for(int i=0;i<n-k;i++){
        result += heightDiff[i];
    }
    
    cout << result << "\n";
    
    
    return 0;
}
