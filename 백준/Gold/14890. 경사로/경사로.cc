#include<iostream>
#include<cmath>
using namespace std;

int n,l;
int boards[100][100];

bool IsPossible(int& cnt, int& sameNum, int currentNum){
    if(sameNum == currentNum){
        cnt++;
        return true;
    }
    
    if(cnt < 0)
        return false;
    
    int diff = abs(sameNum - currentNum);
    if(diff > 1)
        return false;
    
    if(sameNum < currentNum && cnt < l)
        return false;
    else if(sameNum > currentNum){
        sameNum = currentNum;
        cnt = -l + 1;
    }
    else{
        sameNum = currentNum;
        cnt = 1;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> l;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> boards[i][j];
        }
    }
    
    int result = 0;
    for(int i=0;i<n;i++){
        int sameCount = 0;
        int sameNum = boards[i][0];
        bool isEnd = false;
        
        int sameCount2 = 0;
        int sameNum2 = boards[0][i];
        bool isEnd2 = false;
        for(int j=0;j<n;j++){
            int num = boards[i][j];
            if(!isEnd && !IsPossible(sameCount, sameNum, num)){
                isEnd = true;
            }
            
            int num2 = boards[j][i];
            if(!isEnd2 && !IsPossible(sameCount2, sameNum2, num2)){
                isEnd2 = true;
            }
        }
        
        if(!isEnd && sameCount >= 0)
            result++;
        if(!isEnd2 && sameCount2 >= 0)
            result++;
    }
    
    cout << result << "\n";
    
    return 0;
}