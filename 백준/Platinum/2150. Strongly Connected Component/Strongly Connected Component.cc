#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int v,e;
vector<int> map[10001];
int visited[10001] = {0};
bool isSCC[10001] = {false};
int cnt = 1;
stack<int> st;
vector<vector<int>> results;
int solve(int start){
    visited[start] = cnt++;
    st.push(start);
    int minOrder = visited[start];
    vector<int>& graph = map[start];
    for(int i=0;i<graph.size();i++){
        int e = graph[i];
        if(visited[e] == 0)
            minOrder = min(minOrder, solve(e));
        else if(isSCC[e] == false)
            minOrder = min(minOrder, visited[e]);
    }
    
    if(minOrder == visited[start]){
        vector<int> result;
        while(true){
            int t = st.top();
            st.pop();
            isSCC[t] = true;
            result.emplace_back(t);
            if(t == start)
                break;
        }
        isSCC[start] = true;
        sort(result.begin(), result.end());
        results.emplace_back(result);
    }
    
    return minOrder;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> v >> e;
    
    for(int i=0;i<e;i++){
        int from, to;
        cin >> from >> to;
        map[from].emplace_back(to);
    }
    
    for(int i=1;i<=v;i++){
        if(visited[i] == 0)
            solve(i);
    }
    
    sort(results.begin(), results.end());
    cout << results.size() << "\n";
    for(int i=0;i<results.size();i++){
        vector<int>& result = results[i];
        
        for(int i=0;i<result.size();i++){
            cout << result[i] << " ";
        }
        cout << "-1\n";
    }
    
    return 0;
}

