#include<iostream>
#include<algorithm>

using namespace std;

int n;
pair<int, int> works[1000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> works[i].second >> works[i].first;
    }
    
    sort(works, works + n, greater<pair<int, int>>());
    
    
    int currentTime = 10000000;
    for(int i=0;i<n;i++){
        int lastTime = works[i].first;
        int costTime = works[i].second;
        
        if(lastTime < currentTime){
            currentTime = lastTime - costTime;
        }
        else{
            currentTime -= costTime;
        }
        
        if(currentTime < 0){
            currentTime = -1;
            break;
        }
    }
    
    cout << currentTime << "\n";
    return 0;
}
