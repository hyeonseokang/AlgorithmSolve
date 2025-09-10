#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> heights;

long long solve(int l, int r){
    if(l == r){
        return (long long)heights[l];
    }
    
    int m = (l + r) / 2;
    long long result = max(solve(l, m), solve(m + 1, r));
    
    int left = m;
    int right = m + 1;
    long long minHeights = min(heights[left], heights[right]);
    result = max(result, 2 * minHeights);
    while(l < left || right < r){
        int nl = left - 1;
        int nr = right + 1;
        if(right < r && (l == left || heights[nl] < heights[nr])){
            right = nr;
            minHeights = min(minHeights, (long long)heights[nr]);
        }
        else{
            left = nl;
            minHeights = min(minHeights, (long long)heights[nl]);
        }
        
        
        result = max(result, (long long)(right - left + 1) * (long long)minHeights);
    }
    
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(true){
        cin >> n;
        if(n == 0)
            break;
        
        heights.clear();
        heights.resize(n);
        for(int i=0;i<n;i++){
            cin >> heights[i];
        }
        
        cout << solve(0, n-1) << "\n";
    }
    
    return 0;
}
