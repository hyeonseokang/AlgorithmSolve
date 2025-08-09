#include<iostream>
#include<algorithm>
#include<limits.h>
#include<vector>

using namespace std;

int n, m;
vector<int> numbers;
vector<int> segment;
void Init(int idx, int l, int r){
    if(l >= r){
        segment[idx] = numbers[l];
        return;
    }
    
    int m = (l + r) / 2;
    int lIdx = idx * 2;
    int rIdx = idx * 2 + 1;
    
    Init(lIdx, l, m);
    Init(rIdx, m + 1, r);
    
    segment[idx] = min(segment[lIdx], segment[rIdx]);
}

int Query(int a, int b, int l, int r, int idx){
    if(r < a || b < l){
        return INT_MAX;
    }
    if(a <= l && r <= b){
        return segment[idx];
    }
    
    int m = (l + r) / 2;
    int leftNum = INT_MAX, rightNum = INT_MAX;
    
    leftNum = Query(a, b, l, m, idx * 2);
    rightNum = Query(a, b, m+1, r, idx * 2 + 1);
    
    return min(leftNum, rightNum);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    numbers.resize(n);
    segment.resize(n * 4);
    
    for(int i=0;i<n;i++){
        cin >> numbers[i];
    }
    
    Init(1, 0, n - 1);
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        
        cout << Query(a-1, b-1, 0, n-1, 1) << "\n";
    }
    
    return 0;
}
