#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> PAIR;

int n;
vector<PAIR> times;
vector<int> usedCounts;

priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq; // 사용중인 사람
priority_queue<int, vector<int>, greater<int>> blankSeats; // 빈 좌석
int blankSeatCnt = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    times.resize(n);
    
    for(int i=0;i<n;i++){
        cin >> times[i].first >> times[i].second;
    }
    
    sort(times.begin(), times.end());
    usedCounts.emplace_back(1);
    pq.push({times[0].second, 0});
    
    for(int i=1;i<n;i++){
        int s = times[i].first;
        int e = times[i].second;
        
        while(!pq.empty()){
            if(pq.top().first <= s){
                blankSeats.push(pq.top().second);
                pq.pop();
            }
            else
                break;
        }
        
        if(blankSeats.empty()){
            pq.push({e, usedCounts.size()});
            usedCounts.emplace_back(1);
        }
        else{
            usedCounts[blankSeats.top()]++;
            pq.push({e, blankSeats.top()});
            blankSeats.pop();
        }
    }
    
    cout << usedCounts.size() << "\n";
    for(int i=0;i<usedCounts.size();i++){
        cout << usedCounts[i] << " ";
    }
    cout << "\n";
    
    
    return 0;
}
