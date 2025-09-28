#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int n;

long long CalculateGradient(int y, int x){
    return (long long)y *  1000000000 / x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    map<long long, int> gradientRangeMap;
    for(int i=0;i<n;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        long long e = CalculateGradient(y2, x1);
        long long s = CalculateGradient(y1, x2);
        
        gradientRangeMap[s]++;
        gradientRangeMap[e + 1]--;
    }
    
    int temp = 0;
    int result = 0;
    for(auto p:gradientRangeMap){
        temp += p.second;
        result = max(result, temp);
    }
    
    cout << result << "\n";
    
    return 0;
}


