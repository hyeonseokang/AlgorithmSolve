#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> people;
vector<int> parents;
vector<int> visited;

int Find(int x){
    int parent = parents[x];
    
    if(parent == x)
        return parent;
    
    return parents[parent] = Find(parent);
}

void Merge(int a, int b, int nextPoeple){
    int aParent = Find(a);
    int bParent = Find(b);
    
    if(aParent <= bParent){
        parents[bParent] = aParent;
        people[aParent] = nextPoeple;
    }
    else{
        parents[aParent] = bParent;
        people[bParent] = nextPoeple;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    people.resize(n + 1);
    parents.resize(n + 1);
    visited.resize(n + 1);
    for(int i=1;i<=n;i++){
        parents[i] = i;
        cin >> people[i];
    }
    
    for(int i=0;i<m;i++){
        int o, p, q;
        cin >> o >> p >> q;
        
        int pParent = Find(p);
        int qParent = Find(q);
        
        // p와 q가 동맹
        int nextPoeple = 0;
        if(o == 1){
            nextPoeple = people[pParent] + people[qParent];
        }
        else if(o == 2){
            nextPoeple = abs(people[pParent] - people[qParent]);
        }
        
        Merge(p, q, nextPoeple);
    }
    
    vector<int> results;
    for(int i=1;i<=n;i++){
        int parent = Find(i);
        if(visited[parent] == true) continue;
        
        visited[parent] = true;
        
        if(people[parent] == 0) continue;
        
        results.emplace_back(people[parent]);
    }
    
    sort(results.begin(), results.end());
    cout << results.size() << "\n";
    for(int i=0;i<results.size();i++){
        cout << results[i] << " ";
    }
    
    return 0;
}
