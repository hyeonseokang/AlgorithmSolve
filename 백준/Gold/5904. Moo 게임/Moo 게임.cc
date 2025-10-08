#include<iostream>

using namespace std;

int cnts[28] = {0};

void solve(int n, int len, int k){
    if(n <= 3){
        if(n == 1){
            cout << "m\n";
        }
        else{
            cout << "o\n";
        }
        return;
    }
    
    int nLen = len * 2 + k + 4;
    if(nLen <= n){
        solve(n, nLen, k + 1);
    }
    else{
        int mLen = n - len;
        if(mLen == 1){
            cout << "m\n";
        }
        else if(mLen <= k + 4){
            cout << "o\n";
        }
        else{
            solve(mLen - k - 4, 3, 0);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    solve(n, 3, 0);
    return 0;
}