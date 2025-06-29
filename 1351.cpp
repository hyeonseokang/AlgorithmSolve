#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<long long, long long> um;
long long n, p, q;

long long solve(long long i){
    if(i == 0)
        return 1;
    
    if(um.find(i) != um.end())
        return um[i];
    
    um[i] = solve(i / p) + solve(i / q);
    return um[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> p >> q;
    
    cout << solve(n) << "\n";
    
    return 0;
}
