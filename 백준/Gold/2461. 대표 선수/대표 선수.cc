#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int n, m;
vector<pair<int, int>> v;
int classCnts[1000] = {0};
int classTypeCnt = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num;
            cin >> num;
            v.emplace_back(num, i);
        }
    }
    
    sort(v.begin(), v.end());
    int l = 0, r = 0;
    classTypeCnt = 1;
    classCnts[v[0].second]++;
    int result = INT_MAX;
    while(l <= r){
        if(classTypeCnt == n){
            result = min(result, v[r].first - v[l].first);
            classCnts[v[l].second]--;
            if(classCnts[v[l].second] == 0){
                classTypeCnt--;
            }
            l++;
        }
        else if(classTypeCnt > n){
            classCnts[v[l].second]--;
            if(classCnts[v[l].second] == 0){
                classTypeCnt--;
            }
            l++;
        }
        else if(r < v.size() - 1){
            r++;
            classCnts[v[r].second]++;
            if(classCnts[v[r].second] == 1){
                classTypeCnt++;
            }
        }
        else{
            l++;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
