#include<iostream>
#include<algorithm>
#include<limits.h>
#include<deque>
using namespace std;

int n, d;

deque<pair<long long, int>> dq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long result = LONG_LONG_MIN;
    cin >> n >> d;
    for(int i=0;i<n;i++){
        long long nodeScore;
        cin >> nodeScore;
        long long score = nodeScore;
        while(!dq.empty() && i > d + dq.front().second)
            dq.pop_front();
        if(!dq.empty())
            score = max(score, dq.front().first + nodeScore);
        while(!dq.empty() && dq.back().first <= score)
            dq.pop_back();
        
        dq.push_back({score, i});
        result = max(result, score);
    }
    
    cout << result << "\n";
    return 0;
}
