#include<iostream>
#include<vector>
#include<algorithm>
#include <iomanip>

using namespace std;

int n;
typedef pair<int, int> PAIR;
vector<pair<PAIR, PAIR>> points;
int cnts[20001] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    points.reserve(2 * n);
    for(int i=0;i<n;i++){
        float x, y, w, h;
        cin >> x >> y >> w >> h;
        
        points.push_back({make_pair(x * 10, y * 10), make_pair(h * 10, 1)});
        points.push_back({make_pair((x + w) * 10, y * 10), make_pair(h * 10, -1)});
    }
    
    sort(points.begin(), points.end());
    int result = 0;
    int last = points[0].first.first;
    
    for(int i=0;i<points.size();i++){
        int x = points[i].first.first;
        int y = points[i].first.second;
        int h = points[i].second.first;
        int o = points[i].second.second;
        
        int cnt = 0;
        for(int i=0;i<20001;i++){
            if(cnts[i] > 0)
                cnt++;
        }
        
        result += (cnt * (x - last));
        last = x;
        
        for(int i=y;i<y + h;i++){
            cnts[i] += o;
        }
    }
    
    if(result % 100 == 0){
        cout << result / 100 << "\n";
    }
    else{
        cout << fixed << setprecision(2) << result / 100.0 << "\n";
    }
    
    return 0;
}
