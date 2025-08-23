#include<iostream>
#include<vector>

using namespace std;

int n, q;
vector<int> numbers;
vector<long long> segments;
void Init(int idx, int l, int r){
    if(l == r){
        segments[idx] = numbers[l];
        return;
    }
    
    
    int left = idx * 2;
    int m = (l + r) / 2;
    Init(left, l, m);
    Init(left + 1, m + 1, r);
    
    segments[idx] = segments[left] + segments[left + 1];
}

long long Sum(int idx, int l, int r, int cl, int cr){
    if(cl == l && cr == r){
        return segments[idx];
    }
    int m = (l + r) / 2;
    
    long long result = 0;
    
    if(cl <= m){
        result += Sum(idx * 2, l, m, cl, min(m, cr));
    }
    
    if(cr > m){
        result += Sum(idx * 2 + 1, m + 1, r, max(m+1, cl), cr);
    }
    
    return result;
}

void Change(int idx, int l, int r, int cIdx, long long cValue){
    if(l == r){
        segments[idx] = cValue;
        return;
    }
    int m = (l + r) / 2;
    
    if(m >= cIdx){
        Change(idx * 2, l, m, cIdx, cValue);
    }
    else{
        Change(idx * 2 + 1, m + 1, r, cIdx, cValue);
    }
    
    segments[idx] = segments[idx * 2] + segments[idx * 2 + 1];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q;
    segments.resize(4 * n + 1);
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        numbers.emplace_back(num);
    }
    Init(1, 0, n-1);
    for(int i=0;i<q;i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if(x > y){
            int temp = x;
            x = y;
            y = temp;
        }
        
        cout << Sum(1, 1, n, x, y) << "\n";
        Change(1, 1, n, a, b);
    }
    
    return 0;
}
