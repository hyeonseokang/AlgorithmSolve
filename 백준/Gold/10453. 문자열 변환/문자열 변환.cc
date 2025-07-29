#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int t;
string a, b;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    while(t--){
        cin >> a >> b;
        
        int result = 0;
        int aIdx = 0, bIdx = 0;
        
        if(a.size() != b.size()){
            result = -1;
        }
        else{
            while(aIdx < a.size() && bIdx < b.size()){
                result += abs(bIdx - aIdx);
                aIdx++;
                bIdx++;
                
                
                while(aIdx < a.size() && a[aIdx] != 'a'){
                    aIdx++;
                }
                while(bIdx < b.size() && b[bIdx] != 'a'){
                    bIdx++;
                }
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}
