#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<unordered_set>
#include<queue>

using namespace std;

int n;
vector<pair<int, int>> positions;

int CalculateMaxLines(vector<pair<int, int>>& lines, const unordered_set<int>& us){
    sort(lines.begin(), lines.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    
    vector<int> v(us.begin(), us.end());
    sort(v.begin(), v.end());
    
    int result = 0;
    
    for(int i=0;i<lines.size();i++){
        int s = lines[i].first;
        int e = lines[i].second;
        
        while(!pq.empty() && pq.top() <= s){
            pq.pop();
        }
        
        pq.push(e);
        
        auto sIt = lower_bound(v.begin(), v.end(), s);
        auto eIt = lower_bound(v.begin(), v.end(), pq.top());
        if(sIt == v.end() || eIt == v.end() || *sIt != s || *eIt != pq.top()){
            result = max(result, (int)pq.size());
            continue;
        }
        
        int len = abs((int)(eIt - sIt));
        if(s - pq.top() != len){
            result = max(result, (int)pq.size());
            continue;
        }
    }
    
    
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    positions.resize(n);
    for(int i=0;i<n;i++){
        cin >> positions[i].first >> positions[i].second;
    }
    
    vector<pair<int, int>> horizontalLines;
    vector<pair<int, int>> verticalLines;
    unordered_set<int> horizontalSet;
    unordered_set<int> verticalSet;
    for(int i=0;i<n;i++){
        int next = (i + 1) % n;
        if(positions[i].first != positions[next].first){
            int s = positions[i].first;
            int e = positions[next].first;
            
            horizontalLines.emplace_back(min(s, e), max(s, e));
            horizontalSet.insert(positions[i].second);
        }
        if(positions[i].second != positions[next].second){
            int s = positions[i].second;
            int e = positions[next].second;
            
            verticalLines.emplace_back(min(s, e), max(s, e));
            verticalSet.insert(positions[i].first);
        }
    }
    
    int h = CalculateMaxLines(horizontalLines, horizontalSet);
    int v = CalculateMaxLines(verticalLines, verticalSet);
    int result = max(h, v);
    
    cout << result << "\n";
    
    return 0;
}
