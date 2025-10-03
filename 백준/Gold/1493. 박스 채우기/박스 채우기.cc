#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int L, W, H;
int n;
int cubeMaxCtns[20] = {0};
int cubeNeedCnts[20] = {0};
bool isEnd = false;

void CalculateCubeCnt(int l, int w, int h, int idx){
    if(l == 0 || w == 0 || h == 0)
        return;
    
    for(;idx >= 0 ;idx--){
        if(cubeMaxCtns[idx] <= cubeNeedCnts[idx]) continue;
        int num = (1 << idx);
        
        if(l < num || w < num || h < num) continue;
        
        cubeNeedCnts[idx]++;
        
        CalculateCubeCnt(num, w - num, num, idx);
        CalculateCubeCnt(l - num, w, num, idx);
        CalculateCubeCnt(l, w, h - num, idx);
        return;
    }
    
    isEnd = true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> L >> W >> H;
    cin >> n;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        cubeMaxCtns[a] = b;
    }
    CalculateCubeCnt(L, W, H, 19);
    
    int result = 0;
    for(int i=0;i<20;i++){
        result += cubeNeedCnts[i];
    }
    
    if(isEnd == true)
        result = -1;
    cout << result << "\n";
    
    return 0;
}
