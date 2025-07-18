#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>

using namespace std;

typedef pair<double, pair<int, int>> NODE;
int n;
pair<int, int> positions[500];
priority_queue<NODE, vector<NODE>, greater<NODE>> pq;
int parents[500];
vector<double> minDists;

int Find(int x){
    int parent = parents[x];
    
    if(parent == x)
        return parent;
    
    return parents[x] = Find(parent);
}

void Merge(int a, int b){
    int aParent = Find(a);
    int bParent = Find(b);
    
    if(aParent < bParent){
        parents[bParent] = aParent;
    }
    else{
        parents[aParent] = bParent;
    }
}


double GetDist(const pair<int, int>& a, const pair<int, int>& b){
    int y = abs(a.first - b.first);
    int x = abs(a.second - b.second);
    y *= y;
    x *= x;
    return  sqrt(y + x);
}
void Init(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double dist = GetDist(positions[i], positions[j]);
            pq.push({dist, {i, j}});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    while(true){
        cin >> n;
        
        if(n == 0)
            break;
        
        minDists.clear();
        minDists.resize(n, 1500);
        
        for(int i=0;i<n;i++){
            parents[i] = i;
            cin >> positions[i].first >> positions[i].second;
        }
        Init();
        
        while(!pq.empty()){
            NODE node = pq.top();
            pq.pop();
            double dist = node.first;
            int a = node.second.first;
            int b = node.second.second;
            if(minDists[a] >= dist || minDists[b] >= dist){
                Merge(a, b);
                minDists[a] = dist;
                minDists[b] = dist;
            }
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++){
            int parent = Find(i);
            if(minDists[parent] == -1)
                continue;
            minDists[parent] = -1;
            cnt++;
        }
        
        printf("Sky %d contains %d constellations.\n",t, cnt);
        t++;
    }
    return 0;
}
