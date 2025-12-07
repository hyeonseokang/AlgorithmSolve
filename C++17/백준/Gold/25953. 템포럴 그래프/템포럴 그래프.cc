#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n, t, m;
int si, ei;
int dists[10001][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(dists, -1, sizeof(dists));
    
    cin >> n >> t >> m;
    cin >> si >> ei;
    dists[si][0] = 0;
    dists[si][1] = 0;
    for(int i=1;i<=t;i++){
        int prev = i % 2;
        int current = 1 - prev;
        for(int j=0;j<m;j++){
            int s, e, cost;
            cin >> s >> e >> cost;
            
            if(dists[s][prev] != -1){
                int temp = dists[s][prev] + cost;
                if(dists[e][prev] == -1 || dists[e][prev] > temp){
                    dists[e][current] = temp;
                }
            }
            
            if(dists[e][prev] != -1){
                int temp = dists[e][prev] + cost;
                if(dists[s][prev] == -1 || dists[s][prev] > temp){
                    dists[s][current] = temp;
                }
            }
        }
        
        for(int i=0;i<10001;i++){
            dists[i][prev] = dists[i][current];
        }
    }
    
    int result = dists[ei][0];
    if(result > dists[ei][1]){
        result = dists[ei][1];
    }
    
    cout << result << "\n";
    
    return 0;
}