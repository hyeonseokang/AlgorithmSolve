#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, k;

vector<int> parents;

int Find(int x){
    int parent = parents[x];
    if(parent == x)
        return x;
    
    return parents[x] = Find(parent);
}

void Merge(int a, int b){
    int aParent = Find(a);
    int bParent = Find(b);
    
    if(aParent > bParent){
        parents[bParent] = aParent;
    }
    else
        parents[aParent] = bParent;
}
vector<int> cards;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> k;
    parents.resize(n+1);
    cards.resize(m);
    for(int i=0;i<m;i++){
        cin >> cards[i];
    }
    
    sort(cards.begin(), cards.end());
    int prevIndex = 0;
    for(int i=0;i<m;i++){
        for(int j=prevIndex;j<=cards[i];j++){
            parents[j] = cards[i];
        }
        prevIndex = cards[i] + 1;
    }
    for(int i=0;i<k;i++){
        int number;
        cin >> number;
        
        int parent = Find(number+1);
        cout << parent << "\n";
        Merge(parent, parent + 1);
    }
    
    return 0;
}
