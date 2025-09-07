#include<iostream>
#include<vector>

using namespace std;

int n, d, k, c;
vector<int> sushi;
int visitCnt[3001] = {0};
int sushiCnt = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> d >> k >> c;
    sushi.resize(n);
    
    for(int i=0;i<n;i++){
        cin >> sushi[i];
    }
    
    int result = 0;
    for(int i=0;i<k;i++){
        visitCnt[sushi[i]]++;
        if(visitCnt[sushi[i]] == 1)
            sushiCnt++;
    }
    result = visitCnt[c] == 0?sushiCnt + 1: sushiCnt;
    
    for(int l=0;l<n;l++){
        int r = (l + k) % n;
        visitCnt[sushi[l]]--;
        if(visitCnt[sushi[l]] == 0)
            sushiCnt--;
        visitCnt[sushi[r]]++;
        if(visitCnt[sushi[r]] == 1)
            sushiCnt++;
        
        int currntSushiCnt = visitCnt[c] == 0?sushiCnt + 1: sushiCnt;
        result = max(result, currntSushiCnt);
    }
    
    cout << result << "\n";
    
    return 0;
}
