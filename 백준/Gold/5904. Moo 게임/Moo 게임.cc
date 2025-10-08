#include<iostream>

using namespace std;

int cnts[28] = {0};

void solve(int i, int c){
    if(i == 0){
        if(c == 1){
            cout << "m\n";
        }
        else{
            cout << "o\n";
        }
        return;
    }
    
    int prevLen = cnts[i-1];
    if(c <= prevLen){
        solve(i - 1, c);
    }
    else if(c - prevLen == 1){
        cout << "m\n";
    }
    else if(c <= prevLen + i + 3){
        cout << "o\n";
    }
    else{
        solve(i - 1, c - prevLen - i - 3);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int len = 3;
    int i = 0;
    for(i=0;i<1000;){
        cnts[i] = len;
        if(len >= n)
            break;
        i++;
        len = len * 2 + i + 3;
    }
    solve(i, n);
    return 0;
}