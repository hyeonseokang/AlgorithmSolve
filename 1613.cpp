#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;
int n, k;

vector<int> relations[401];
bool visited[401][401] = {false};

void BFS(int s){
    queue<int> q;
    q.push(s);
    
    while(!q.empty()){
        int current = q.front();
        q.pop();
        
        const vector<int> relation = relations[current];
        for(int i=0;i<relation.size();i++){
            int next = relation[i];
            if(visited[s][next] == true)
                continue;
            
            visited[s][next] = true;
            q.push(next);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    for(int i=0;i<k;i++){
        int firstEvent, secondEvent;
        cin >> firstEvent >> secondEvent;
        relations[firstEvent].emplace_back(secondEvent);
    }
    
    for(int i=1;i<=n;i++){
        BFS(i);
    }
    
    int s;
    cin >> s;
    for(int i=0;i<s;i++){
        int from, to;
        cin >> from >> to;
        
        int result = 0;
        if(visited[from][to] == true)
            result = -1;
        else if(visited[to][from] == true)
            result = 1;
        else
            result = 0;
        
        cout << result << "\n";
    }
    
    return 0;
}
