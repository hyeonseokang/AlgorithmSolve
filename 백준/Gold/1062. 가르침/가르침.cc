#include<iostream>
#include<string>
#include<algorithm>
#include<limits.h>

using namespace std;

int n, k;
string words[50];
int alphabetBits[50];
pair<int, char> alphabetCnts[26];
int maxResult = 0;

void solve(int len, int i, int bit){
    if(len == k){
        int result = 0;
        for(int idx=0;idx<n;idx++){
            if(alphabetBits[idx] == (bit & alphabetBits[idx])){
                result++;
            }
        }
        maxResult = max(maxResult, result);
        return;
    }
    
    for(;i<26;i++){
        if((bit & (1 << i)) == true)
            continue;
        int idx = alphabetCnts[i].second - 'a';
        int nextBit = (bit | (1 << idx));
        solve(len + 1, i+1, nextBit);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0;i<26;i++){
        alphabetCnts[i] = {0, 'a' + i};
    }
    
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> words[i];
        
        int bit = 0;
        for(int j=0;j<words[i].size();j++){
            alphabetCnts[words[i][j] - 'a'].first++;
            
            int index = words[i][j] - 'a';
            bit = (bit | (1 << index));
        }
        alphabetBits[i] = bit;
    }
    
    sort(alphabetCnts, alphabetCnts + 26, greater<pair<int, char>>());
    // anta tica => a, n, t, i, c
    if(k >= 5){
        int bit = 0;
        string s = "antic";
        for(int i=0;i<s.size();i++){
            bit = (bit | (1 << (s[i] - 'a')));
        }
        solve(5, 0, bit);
    }
    
    cout << maxResult << "\n";
    
    return 0;
}
