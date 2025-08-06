#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n;
typedef pair<pair<int, int>, int> PAIR;
priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
vector<int> results;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    results.resize(n + 1);
    
    for(int i=0;i<n;i++){
        int number, s, e;
        cin >> number >> s >> e;
        
        pq.push({{s, e}, number});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> classRooms;
    classRooms.push({0, 1});
    
    while(!pq.empty()){
        int num = pq.top().second;
        int s = pq.top().first.first;
        int e = pq.top().first.second;
        pq.pop();
        
        int classEndTime = classRooms.top().first;
        int classNumber = classRooms.top().second;
        
        if(classEndTime <= s){
            classRooms.pop();
            classRooms.push({e, classNumber});
            results[num] = classNumber;
        }
        else{
            classRooms.push({e, classRooms.size() + 1});
            results[num] = classRooms.size();
        }
    }
    
    cout << classRooms.size() << "\n";
    
    for(int i=1;i<results.size();i++){
        cout << results[i] << "\n";
    }
    return 0;
}
