#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<limits.h>
#include<unordered_map>

using namespace std;

int n;
vector<int> heights;
vector<int> snowman;
unordered_map<int, pair<int,int>> um;

bool IsPossibleHeight(const pair<int, int>& p, int i, int j){
    return !(i == p.first || j == p.first || i == p.second || j == p.second);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    heights.resize(n);
    for(int i=0;i<n;i++){
        cin >> heights[i];
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int height = heights[i] + heights[j];
            snowman.emplace_back(height);
            um[height] = {i, j};
        }
    }
    
    int result = INT_MAX;
    sort(snowman.begin(), snowman.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int height = heights[i] + heights[j];
            auto lowerIt = lower_bound(snowman.begin(), snowman.end(), height);
            if(lowerIt != snowman.end()){
                if(IsPossibleHeight(um[*lowerIt], i, j) == true){
                    result = min(result, abs(height - *lowerIt));
                }
                
            }
            if(lowerIt != snowman.begin())
                lowerIt--;
            if(IsPossibleHeight(um[*lowerIt], i, j) == true){
                result = min(result, abs(height - *lowerIt));
            }
            
            
            auto upperIt = upper_bound(snowman.begin(), snowman.end(), height);
            if(upperIt == snowman.end())
                upperIt--;
            if(IsPossibleHeight(um[*upperIt], i, j) == true){
                result = min(result, abs(height - *upperIt));
            }
        
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
