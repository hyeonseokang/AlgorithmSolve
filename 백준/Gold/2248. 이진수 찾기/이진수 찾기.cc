#include<iostream>
using namespace std;

int ncr[32][32] = {0};

void solve(int n, int l, long long i){
    if(n == 0 || l == 0){
        for(int i=0;i<n;i++){
            cout << "0";
        }
        cout << "\n";
        return;
    }
    
    long long skip = 0;
    for(int i=0;i<=l;i++){
        skip += ncr[n-1][i];
    }
    
    if(i <= skip){
        cout << "0";
        solve(n-1,l,i);
    }
    else{
        cout << "1";
        solve(n-1,l-1, i - skip);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, l;
    long long i;
    cin >> n >> l >> i;
    ncr[0][0] = 1;
    for(int i=0;i<32;i++){
        ncr[i][0] = 1;
        ncr[i][i] = 1;
    }
    
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
        }
    }
    
    solve(n, l, i);
    
    
    return 0;
}