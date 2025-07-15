#include<iostream>
#include<algorithm>
#include<limits.h>

using namespace std;

int heights[50] = {0};
int n;

double GetGradient(int y1, int x1, int y2, int x2){
    return (double)(y1 - y2) / (double)(x1 - x2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> heights[i];
    }
    
    int result = 0;
    for(int i=0;i<n;i++){
        int visibleCount = 0;
        int height = heights[i];
        double minGradient = INT_MAX;
        for(int j=i-1;j>=0;j--){
            double gradient = GetGradient(height, i, heights[j], j);
            if(minGradient > gradient){
                minGradient = gradient;
                visibleCount++;
            }
        }
        double maxGradient = INT_MIN;
        for(int j=i+1;j<n;j++){
            double gradient = GetGradient(height, i, heights[j], j);
            if(maxGradient < gradient){
                maxGradient = gradient;
                visibleCount++;
            }
        }
        
        result = max(result, visibleCount);
    }
    
    cout << result << "\n";
    
    
    
    return 0;
}
