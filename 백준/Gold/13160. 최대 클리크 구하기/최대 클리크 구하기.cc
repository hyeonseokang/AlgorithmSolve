#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int n;
map<int, int> m;
vector<pair<int, int>> lines;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    lines.resize(n + 1);
    for(int i=1;i<=n;i++){
        int s, e;
        cin >> s >> e;
        lines[i] = make_pair(s, e);
        m[s]++;
        m[e + 1]--;
    }
    
    int temp = 0;
    int result = 0;
    int maxNumber = 0;
    for(auto& p: m){
        temp += p.second;
        
        if(result < temp){
            result = temp;
            maxNumber = p.first;
        }
    }
    
    cout << result << "\n";
    for(int i=1;i<=n;i++){
        if(maxNumber < lines[i].first || maxNumber > lines[i].second)
            continue;
        
        cout << i << " ";
    }
    
    cout << "\n";
    
    
    
    
    return 0;
}