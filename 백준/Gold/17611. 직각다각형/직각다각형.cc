#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n;
vector<pair<int, int>> positions;

int CalculateMaxLines(vector<pair<int, int>>& lines){
    sort(lines.begin(), lines.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int result = 0;
    
    for(int i=0;i<lines.size();i++){
        int s = lines[i].first;
        int e = lines[i].second;
        
        while(!pq.empty() && pq.top() <= s){
            pq.pop();
        }
        
        pq.push(e);
        result = max(result, (int)pq.size());
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
    for(int i=0;i<n;i++){
        int next = (i + 1) % n;
        if(positions[i].first != positions[next].first){
            int s = positions[i].first;
            int e = positions[next].first;
            
            horizontalLines.emplace_back(min(s, e), max(s, e));
        }
        if(positions[i].second != positions[next].second){
            int s = positions[i].second;
            int e = positions[next].second;
            
            verticalLines.emplace_back(min(s, e), max(s, e));
        }
    }
    
    int h = CalculateMaxLines(horizontalLines);
    int v = CalculateMaxLines(verticalLines);
    int result = max(h, v);
    
    cout << result << "\n";
    
    return 0;
}