#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

int r, c;
string s[1000];
unordered_set<string> us;
string rowString[1000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    cin >> r >> c;
    for(int i=0;i<r;i++){
        cin >> s[i];
    }
    
    int result = 0;
    for(int i=r-1;i>=0;i--){
        us.clear();
        int j = 0;
        bool isEnd = true;
        for(;j<c;j++){
            rowString[j].push_back(s[i][j]);
            if(us.insert(rowString[j]).second == false){
                isEnd = false;
            }
        }
        
        if(isEnd == true){
            result = i;
            break;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
