#include<iostream>
#include<string>
#include<map>

using namespace std;

int n, m, k;
string lampMap[50];
map<string, int> patterns;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> lampMap[i];
    }
    cin >> k;
    
    for(int y=0;y<n;y++){
        int zeroCnt = 0;
        for(int x=0;x<m;x++){
            if(lampMap[y][x] == '0'){
                zeroCnt++;
            }
        }
        
        if(zeroCnt <= k && zeroCnt % 2 == k % 2){
            patterns[lampMap[y]]++;
        }
    }
    
    int result = 0;
    for(const pair<string, int> p:patterns){
        result = max(result, p.second);
    }
    
    cout << result << "\n";
    return 0;
}
