#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, c;
int m;

struct Node{
    int a, b, boxSize;
    
    Node(){
        
    }
    
    Node(int _a, int _b, int _boxSize):a(_a), b(_b), boxSize(_boxSize){
        
    }
    
    bool operator <(const Node& other)const{
        if(a != other.a)
            return a < other.a;
        
        if(b != other.b)
            return b < other.b;
        
        return boxSize < other.boxSize;
    }
};

vector<Node> nodes;
int town[2001] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> c;
    cin >> m;
    for(int i=0;i<m;i++){
        int a, b, boxSize;
        cin >> a >> b >> boxSize;
        
        nodes.emplace_back(a, b, boxSize);
    }
    
    
    sort(nodes.begin(), nodes.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    
    int result = 0;
    int i=0;
    int weight = 0;
    for(int num = 1;num <= n;num++){
        for(;i<m;i++){
            if(nodes[i].a > num) break;
            int b = nodes[i].b;
            int boxSize = nodes[i].boxSize;
            town[b] += boxSize;
            weight += boxSize;
            pq.push({b, boxSize});
        }
        
        weight -= town[num];
        while(!pq.empty() && weight > c){
            if(weight - pq.top().second > c){
                town[pq.top().first] -= pq.top().second;
                weight -= pq.top().second;
                pq.pop();
            }
            else{
                int temp = pq.top().second - weight + c;
                town[pq.top().first] += temp;
                weight += temp;
                pq.push({pq.top().first, temp});
                
                town[pq.top().first] -= pq.top().second;
                weight -= pq.top().second;
                pq.pop();
            }
        }
    }
    
    while(!pq.empty()){
        result += pq.top().second;
        pq.pop();
    }
    cout << result << "\n";
    
    return 0;
}
