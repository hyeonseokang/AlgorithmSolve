#include<iostream>
#include<queue>
#include<algorithm>
#include<set>

using namespace std;

int sumNum;
bool visited[1501][1501] = {false};
int A, B, C;
struct Stone{
    union{
        int stone[2];
        struct{
            int a;
            int b;
        };
    };
    
    Stone(int a, int b):a(a), b(b){
        
    }
};

set<Stone> s;

void Add(queue<Stone> &q, int a, int b){
    int ca = a + a;
    int cb = b - a;
    int cc = sumNum - (a + b);
    
    if(ca > cc)
        swap(ca, cc);
    if(cb > cc)
        swap(cb, cc);
    if(ca > cb)
        swap(ca, cb);
    
    if(ca < 0 || cc > sumNum)
        return;
    
    if(visited[ca][cb] == false){
        visited[ca][cb] = true;
        q.push(Stone(ca, cb));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> A >> B >> C;
    sumNum = A + B + C;
    if(A > C)
        swap(A, C);
    if(B > C)
        swap(B, C);
    if(A > B)
        swap(A, B);
    
    queue<Stone> q;
    q.push(Stone(A, B));
    visited[A][B] = true;
    
    bool isSuccess = false;
    while(!q.empty()){
        Stone stone = q.front();
        q.pop();
        int c = sumNum - (stone.a + stone.b);
        if(stone.a == stone.b && stone.b == c){
            isSuccess = true;
            break;
        }
        
        if(stone.a != stone.b)
            Add(q, stone.a, stone.b);
        if(stone.a != c)
            Add(q, stone.a, c);
        if(stone.b != c)
            Add(q, stone.b, c);
    }
    
    cout << isSuccess << "\n";
    
    return 0;
}
