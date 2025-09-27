#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
vector<pair<int, int>> positions; // x좌표, y좌표
vector<pair<pair<int, int>, int>> lines;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    positions.resize(n + 1);
    for(int i=1;i<=n;i++){
        cin >> positions[i].first >> positions[i].second;
    }
    
    lines.resize(m);
    for(int i=0;i<m;i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        lines[i].first.first = positions[a].second;
        lines[i].first.second = positions[b].second;
        
        if(lines[i].first.first > lines[i].first.second)
            swap(lines[i].first.first, lines[i].first.second);
        
        lines[i].second = cost;
    }
    
    sort(lines.begin(), lines.end());
    
    long long sumCost = 0;
    long long result = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i=0;i<lines.size();i++){
        int s = lines[i].first.first;
        int e = lines[i].first.second;
        int cost = lines[i].second;
        
        while(!pq.empty() && pq.top().first < s){
            sumCost -= pq.top().second;
            pq.pop();
        }
        
        sumCost += cost;
        pq.push({e, cost});
        result = max(result, sumCost);
    }
    
    cout << result << "\n";
    return 0;
}

