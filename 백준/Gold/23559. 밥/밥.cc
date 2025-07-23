#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, balance;
vector<pair<int, int>> menu;

bool Compare(const pair<int, int>& a, const pair<int, int>& b){
    int aDiff = a.first - a.second;
    int bDiff = b.first - b.second;

    return aDiff > bDiff;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> balance;
    int result = 0;
    
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        if(a <= b){
            balance -= 1000;
            result += b;
        }
        else{
            menu.emplace_back(a, b);
        }
    }
    
    if(menu.empty() == false){
        sort(menu.begin(), menu.end(), Compare);
        int minBuyCount = (balance - (menu.size() * 1000)) / 4000;
        minBuyCount = min(minBuyCount, (int)menu.size());
        for(int i=0;i<minBuyCount;i++){
            result += menu[i].first;
        }
        
        for(int i=minBuyCount;i<menu.size();i++){
            result += menu[i].second;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
