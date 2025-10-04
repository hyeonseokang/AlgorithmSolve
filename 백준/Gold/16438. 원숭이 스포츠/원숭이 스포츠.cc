#include<iostream>

using namespace std;

int n;
char teams[7][100];

void Solve(int len, int s, int e){
    if(s >= e){
        char c = 'A';
        if(s == 0)
            c = 'B';
        for(;len < 7;len++){
            teams[len][s] = c;
        }
        return;
    }
    int m = (s + e) / 2;
    int i = s;
    for(;i<=m;i++){
        teams[len][i] = 'A';
    }
    for(;i<=e;i++){
        teams[len][i] = 'B';
    }
    
    Solve(len + 1, s, m);
    Solve(len + 1, m + 1, e);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    Solve(0, 0, n - 1);
    
    for(int i=0;i<7;i++){
        for(int j=0;j<n;j++){
            cout << teams[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}
