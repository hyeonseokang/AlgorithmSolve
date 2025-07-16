#include<iostream>
#include<vector>

using namespace std;

vector<int> numbers;
vector<int> segmentTree;
void Init(int idx, int l, int r){
    if(l == r){
        segmentTree[idx] = l;
        return;
    }
    // 1 ~ 5
    int nextIdx = idx * 2;
    int m = (l + r) / 2;
    Init(nextIdx, l, m);
    Init(nextIdx + 1, m + 1, r);
    
    int lIdx = segmentTree[nextIdx];
    int rIdx = segmentTree[nextIdx + 1];
    
    if(numbers[lIdx] <= numbers[rIdx]){
        segmentTree[idx] = lIdx;
    }
    else{
        segmentTree[idx] = rIdx;
    }
}


void Change(int i, int newValue, int l, int r, int idx){
    if(l == r){
        numbers[l] = newValue;
        return;
    }
    int nextIdx = idx * 2;
    int m = (l + r) / 2;
    if(m >= i){
        Change(i, newValue, l, m, nextIdx);
    }
    else{
        Change(i, newValue, m + 1, r, nextIdx + 1);
    }
    
    
    int lIdx = segmentTree[nextIdx];
    int rIdx = segmentTree[nextIdx + 1];
    
    if(numbers[lIdx] <= numbers[rIdx]){
        segmentTree[idx] = lIdx;
    }
    else{
        segmentTree[idx] = rIdx;
    }
}

void Print(){
    int idx = segmentTree[1];
    cout << idx << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    numbers.resize(n + 1);
    segmentTree.resize(numbers.size() * 3 + 1);
    for(int i=1;i<=n;i++){
        cin >> numbers[i];
    }
    
    Init(1, 1, n);
    
    int m;
    cin >> m;
    while(m--){
        int oper;
        cin >> oper;
        if(oper == 1){
            int i, newValue;
            cin >> i >> newValue;
            Change(i, newValue, 1, n, 1);
        }
        else if(oper == 2){
            Print();
        }
    }
}
