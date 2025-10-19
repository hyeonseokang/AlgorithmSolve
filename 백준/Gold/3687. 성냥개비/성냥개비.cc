#include<iostream>
#include<string>

using namespace std;

int numCnts[10] = {
    6, 2, 5, 5, 4, 5, 6, 3, 7, 6
};

int t;
string dp[101] = {};

bool CompareString(const string& a, const string& b){
    int maxSize = max(a.size(), b.size());
    for(int i=0;i<maxSize;i++){
        if(a[i % a.size()] == b[i % b.size()]) continue;
        
        return a[i % a.size()] < b[i % b.size()];
    }
    
    return true;
}

bool CompareStringOrder(const string& a, const string& b){
    if(a.size() == b.size()){
        return a < b;
    }
    
    return a.size() < b.size();
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    dp[2] = "1";
    dp[3] = "7";
    dp[4] = "4";
    dp[5] = "2";
    dp[6] = "6";
    dp[7] = "8";
    
    for(int i=8;i<101;i++){
        dp[i] = dp[i-6] + "0";
        for(int j=2;j <= i/2;j++){
            string s;
            if(CompareString(dp[j], dp[i-j])){
                s = dp[j] + dp[i-j];
            }
            else{
                s = dp[i-j] + dp[j];
            }
            
            if(dp[i].empty() || CompareStringOrder(s, dp[i]))
                dp[i] = s;
        }
    }
    
    
    
    cin >> t;
    while(t--){
        int stickCnt;
        cin >> stickCnt;
        string minNum = dp[stickCnt];
        string maxNum;
        while(stickCnt != 0){
            if(stickCnt % 2 == 0){
                maxNum += '1';
                stickCnt -= 2;
            }
            else{
                maxNum += '7';
                stickCnt -= 3;
            }
        }
        
        cout << minNum << " " << maxNum << "\n";
    }
    
    return 0;
}