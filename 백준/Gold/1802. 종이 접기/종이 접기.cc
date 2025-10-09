#include<iostream>
#include<string>

using namespace std;

int t;

bool solve(const string& s, int l, int r){
    int m = (l + r) / 2;
    int len = r - l + 1;
    if(len == 1){
        return true;
        
    }
    if(len == 3){
        return s[l] != s[r];
    }
    
    int i = l;
    int j = r;
    while(i < m){
        if(s[i] == s[j])
            return false;
        
        i++;
        j--;
    }
    
    if(s[m] == '0'){
        return solve(s, l, m - 1);
    }
    else{
        return solve(s, m + 1, r);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        bool result = solve(s, 0, s.size() - 1);
        
        if(result == true){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    
    return 0;
}