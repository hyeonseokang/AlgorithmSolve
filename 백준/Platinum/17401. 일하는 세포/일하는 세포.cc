#include<iostream>
#include<vector>

using namespace std;

int t, n, d;
const int MOD = 1000000007;
vector<vector<int>> originalMatrix[100];

void CalculateMatrix(vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& outMatrix){
    
    vector<vector<int>> temp(outMatrix.size(), vector<int>(outMatrix.size()));
    
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            temp[i][j] = 0;
            for(int k=0;k<a.size();k++){
                long long value = (long long)a[i][k] * b[k][j];
                value %= MOD;
                temp[i][j] += value;
                temp[i][j] %= MOD;
            }
        }
    }
    
    for(int i=0;i<outMatrix.size();i++){
        for(int j=0;j<outMatrix.size();j++){
            outMatrix[i][j] = temp[i][j] % MOD;
        }
    }
}

void CalculateMatrixExp(vector<vector<int>>& matrix, int exp, vector<vector<int>>& outMatrix){
    if(exp == 1){
        outMatrix = matrix;
        return;
    }
    
    vector<vector<int>> original(matrix);
    
    vector<vector<int>> halfMatrix(matrix.size(), vector<int>(matrix.size(), 0));
    
    CalculateMatrixExp(matrix, exp/2, halfMatrix);
    
    CalculateMatrix(halfMatrix, halfMatrix, outMatrix);
    if(exp % 2 == 1){
        vector<vector<int>> newOutMatrix(outMatrix.size(), vector<int>(outMatrix.size(), 0));
        
        CalculateMatrix(outMatrix, original, newOutMatrix);
        outMatrix = newOutMatrix;
    }
}

void Print(vector<vector<int>>& matrix){
    for(int i=1;i<matrix.size();i++){
        for(int j=1;j<matrix[i].size();j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t >> n >> d;
    
    for(int i=0;i<t;i++){
        int m;
        cin >> m;
        originalMatrix[i].resize(n+1, vector<int>(n+1, 0));
        for(int j=0;j<m;j++){
            int a, b, c;
            cin >> a >> b >> c;
            originalMatrix[i][a][b] = c;
        }
    }
    
    vector<vector<int>> modMatrix(originalMatrix[0].size(), vector<int>(originalMatrix[0].size()));
    for(int i=1;i<=n;i++){
        modMatrix[i][i] = 1;
    }
    vector<vector<int>> result(modMatrix);
    for(int i=0;i<(d%t);i++){
        CalculateMatrix(modMatrix, originalMatrix[i], modMatrix);
    }
    
    if(d/t == 0){
        Print(modMatrix);
    }
    else{
        vector<vector<int>> periodMatrix(modMatrix);
        for(int i=(d%t);i<t;i++){
            CalculateMatrix(periodMatrix, originalMatrix[i], periodMatrix);
        }
        
        CalculateMatrixExp(periodMatrix, d/t, result);
        if(d%t > 0){
            CalculateMatrix(result, modMatrix, result);
        }
        Print(result);
    }
    
    
    return 0;
}
