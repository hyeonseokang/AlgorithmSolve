#include<iostream>
#include<algorithm>
#include<limits.h>

using namespace std;

int numbers[100000];
int n, m;

struct Node{
    int minNum;
    int maxNum;
    
    Node* left;
    Node* right;
};

Node* Init(int a, int b){
    Node* node = new Node();
    if(a == b){
        node->minNum = numbers[a];
        node->maxNum = numbers[b];
        return node;
    }
    
    int mid = (a + b) / 2;
    Node* left = Init(a, mid);
    Node* right = Init(mid + 1, b);
    
    node->minNum = min(left->minNum, right->minNum);
    node->maxNum = max(left->maxNum, right->maxNum);
    
    node->left = left;
    node->right = right;
    return node;
}

Node* parent;
// 9 9 0 9
//
pair<int,int> solve(Node* node, int a, int b, int ca, int cb){
    if(a == ca && b == cb){
        return {node->minNum, node->maxNum};
    }
    
    Node* left = node->left;
    Node* right = node->right;
    
    int mid = (ca + cb) / 2;
    pair<int,int> leftResult = {INT_MAX, INT_MIN};
    pair<int,int> rightResult = {INT_MAX, INT_MIN};
    if(a <= mid){
        leftResult = solve(left, a, min(b, mid), ca, mid);
    }
    
    if(b > mid){
        rightResult = solve(right, max(a, mid+1), b, mid+1, cb);
    }
    
    pair<int,int> result = {-1, -1};
    result.first = min(leftResult.first, rightResult.first);
    result.second = max(leftResult.second, rightResult.second);
    
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> numbers[i];
    }
    
    parent = Init(0, n - 1);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        
        pair<int,int> result = solve(parent, a-1, b-1, 0, n-1);
        cout << result.first << " " << result.second << "\n";
    }
    
    
    return 0;
}
