#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;
long long map[100];
int indexCount[38] = {0};
// 100000000000
int solve(bool isTurn){
    
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> map[i];
        for(int j=0;j<38;j++){
            indexCount[j] += (map[i] >> j) & 1;
        }
    }
    
    bool isSuccess = false;
    for(int j=0;j<38;j++){
        if(indexCount[j] % 2 == 1){
            isSuccess = true;
            break;
        }
    }
    
    if(isSuccess)
        cout << "koosaga\n";
    else
        cout << "cubelover\n";
    
    return 0;
}
