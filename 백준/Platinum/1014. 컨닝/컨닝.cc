#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int n, m;
string classroom[10];

int dp[11][1 << 10] = {0};

void GetPossibleBit(vector<int>& candidateBit, int prevBit, int i, int bit, int line){
    if(i >= m){
        candidateBit.emplace_back(bit);
        return;
    }
    for(;i<m;i++){
        if(classroom[line][i] == 'x') continue;
        if(i > 0 && prevBit & (1 << (i - 1))) continue;
        if(i < m - 1 && prevBit & (1 << (i + 1))) continue;
        int next = bit | (1 << i);
        GetPossibleBit(candidateBit, prevBit, i + 2, next, line);
    }
    
    candidateBit.emplace_back(bit);
}

int GetBitOneCnt(int bit){
    int cnt = 0;
    while(bit != 0){
        bit &= (bit - 1);
        cnt ++;
    }
    
    return cnt;
}

int solve(int line, int prevBit){
    if(line >= n)
        return 0;
    
    vector<int> candidateBit;
    GetPossibleBit(candidateBit, prevBit, 0, 0, line);
    
    int& ret = dp[line][prevBit];
    if(ret != -1)
        return ret;
    
    for(int i=0;i<candidateBit.size();i++){
        int bit = candidateBit[i];
        int next = solve(line + 1, bit);
    
        
        ret = max(ret, GetBitOneCnt(bit) + next);
    }
    
    return ret;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int c;
    cin >> c;
    while(c--){
        memset(dp, -1, sizeof(dp));
        
        cin >> n >> m;
        for(int i=0;i<n;i++){
            cin >> classroom[i];
        }
        
        int result = solve(0, 0);
        cout << result << "\n";
    }
    
    return 0;
}

