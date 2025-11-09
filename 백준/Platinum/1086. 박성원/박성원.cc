#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

int n, k;
int fullBit = 0;
string s[15];
long long dp[1 << 15][100];
long long modCache[51];
long long modCacheStr[15];

long long Modular(const string& s, const int& k){
    long long result = 0;
    for(int i=0;i<s.size();i++){
        char c = s[i];
        result *= 10;
        result += c - '0';
        result %= k;
    }
    
    return result;
}
long long GCD(long long a, long long b){
    while(a != 0){
        long long remainder = b % a;
        b = a;
        a = remainder;
    }
    
    return b;
}
long long solve(int bit, int mod){
    if(bit == fullBit){
        if(mod == 0) return 1;
        
        return 0;
    }
    
    long long& ret = dp[bit][mod];
    if(ret != -1)
        return ret;
    
    ret = 0;
    for(int i=0;i<n;i++){
        int visited = (bit & (1 << i));
        if(visited != 0) continue;
        
        int next = (bit | (1 << i));
        int nextMod = mod * modCache[s[i].size()] + modCacheStr[i];
        nextMod %= k;
        ret += solve(next, nextMod);
    }
    
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    cin >> k;
    
    memset(dp, -1, sizeof(dp));
    fullBit = (1 << n) - 1;
    
    for(int i=0;i<n;i++){
        modCacheStr[i] = Modular(s[i], k);
    }
    
    modCache[0] = 1;
    for(int i=1;i<51;i++){
        modCache[i] = ((modCache[i-1] * 10)%k);
    }
    
    long long result = solve(0, 0);
    long long b = 1;
    
    for(int i=2;i<=n;i++){
        if(result % i == 0){
            result /= i;
            continue;
        }
        
        b *= i;
    }
    
    
    int gcd = GCD(result, b);
    
    cout << result/gcd << "/" << b/gcd <<  "\n";
    
    return 0;
}
