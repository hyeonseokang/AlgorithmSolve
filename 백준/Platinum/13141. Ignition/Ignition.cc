#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;

int n, m;
vector<pair<pair<int, int>, int>> graph;
int map[201][201] = {0};

int solve(int start){
    
    int result = 0;
    for(int i=0;i<graph.size();i++){
        int to = graph[i].first.first;
        int from = graph[i].first.second;
        int dist = graph[i].second;
        
        int toTime = map[start][to];
        int fromTime = map[start][from];
        
        int time = 0;
        int diff = abs(toTime - fromTime);
        if(diff < dist){
            time = max(toTime, fromTime) + ((dist - diff) / 2);
        }
        else{
            time = min(toTime, fromTime) + dist;
        }
        
        result = max(result, time);
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int to, from, dist;
        cin >> to >> from >> dist;
        dist *= 2;
        if(map[to][from] == 0 || dist < map[to][from]){
            map[to][from] = dist;
            map[from][to] = dist;
        }
        graph.emplace_back(make_pair(to, from), dist);
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i == j) continue;
                if(map[i][k] == 0 || map[k][j] == 0) continue;
                
                if(map[i][j] == 0 || map[i][j] > map[i][k] + map[k][j]){
                    map[i][j] = map[i][k] + map[k][j];
                    map[j][i] = map[j][k] + map[k][i];
                }
            }
        }
    }
    
    int result = solve(1);
    for(int i=2;i<=n;i++){
        result = min(result , solve(i));
    }
    
    cout << fixed << setprecision(1) << ((double)result / 2) << "\n";
    return 0;
}
