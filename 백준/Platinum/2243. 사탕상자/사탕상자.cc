#include<iostream>
using namespace std;

int n;
const int M = (1 << 20);
int nodes[2 * M + 1] = {0};

void Push(int tasteLevel, int value){
    tasteLevel = tasteLevel + M - 2;
    while(tasteLevel > 0){
        nodes[tasteLevel] += value;
        tasteLevel = (tasteLevel - 1)/2;
    }
    nodes[tasteLevel] += value;
}

void Pop(int rank){
    int idx = 0;
    while(idx < M - 1){
        nodes[idx]--;
        idx = (idx * 2 + 1);
        if(rank <= nodes[idx]){
            
        }
        else{
            rank -= nodes[idx];
            idx++;
        }
    }
    
    
    nodes[idx]--;
    cout << idx - M + 2 << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    
    for(int i=0;i<n;i++){
        int a, b, c;
        cin >> a >> b;
        if(a == 1){
            Pop(b);
        }
        else if(a == 2){
            cin >> c;
            Push(b, c);
        }
    }
    
    return 0;
}
