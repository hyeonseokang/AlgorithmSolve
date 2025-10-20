#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
typedef pair<pair<int, int>, pair<int, int>> PAIR;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    vector<PAIR> bricks;
    for(int i=1;i<=n;i++){
        int w, h, weight;
        cin >> w >> h >> weight;
        
        bricks.emplace_back(make_pair(w, weight), make_pair(h, i));
    }
    
    sort(bricks.begin(), bricks.end());
    vector<int> prev(bricks.size() + 1);
    vector<int> maxHeights(bricks.size() + 1);
    
    int maxHeight = 0;
    int maxNumber = 0;
    
    for(int i=bricks.size() - 1;i>=0;i--){
        int num = bricks[i].second.second;
        int h = bricks[i].second.first;
        int weight = bricks[i].first.second;
        maxHeights[num] = 0;
        prev[num] = num;
        for(int j=bricks.size() - 1;j>i;j--){
            int prevNum = bricks[j].second.second;
            int prevWeight = bricks[j].first.second;
            if(weight > prevWeight) continue;
            
            if(maxHeights[num] < maxHeights[prevNum]){
                maxHeights[num] = maxHeights[prevNum];
                prev[num] = prevNum;
            }
        }
        
        maxHeights[num] += h;
        
        if(maxHeight < maxHeights[num]){
            maxHeight = maxHeights[num];
            maxNumber = num;
        }
    }
    
    vector<int> numbers;
    while(true){
        numbers.emplace_back(maxNumber);
        if(maxNumber == prev[maxNumber])
            break;
        maxNumber = prev[maxNumber];
    }
    
    cout << numbers.size() << "\n";
    for(int i=0;i<numbers.size();i++){
        cout << numbers[i] << "\n";
    }
    
    return 0;
}
