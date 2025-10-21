#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
vector<int> inDegree;
vector<int> graph;
vector<long long> nodeValues;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    inDegree.resize(n + 1);
    graph.resize(n + 1);
    nodeValues.resize(n + 1, 0);
    
    for(int i=2;i<=n;i++){
        char t;
        int a, p;
        cin >> t >> a >> p;
        
        if(t == 'S'){
            nodeValues[i] = a;
        }
        else if(t == 'W'){
            nodeValues[i] = -a;
        }
        graph[i] = p;
        inDegree[p]++;
    }
    
    
    queue<int> q;
    for(int i=2;i<=n;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int s = q.front();
        q.pop();
        
        long long value = nodeValues[s];
        int next = graph[s];
        
        if(value > 0){
            nodeValues[next] += value;
        }
        
        inDegree[next]--;
        if(inDegree[next] == 0){
            q.push(next);
        }
    }
    
    cout << nodeValues[1] << "\n";
    
    return 0;
}