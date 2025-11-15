#include<iostream>
#include<vector>
using namespace std;

int d;

 vector<vector<int>> v = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 1, 0}
};

vector<vector<int>> result = {
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1},
};

constexpr int MOD = 1'000'000'007;
vector<vector<int>> MultiPly(const vector<vector<int>>& A, const vector<vector<int>>& B){
    
    vector<vector<int>> result(A.size(), vector<int>(B[0].size(), 0));
    
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            for(int k=0;k<8;k++){
                result[i][j] += ((long long)A[i][k] * B[k][j]) % MOD;
                result[i][j] %= MOD;
            }
        }
    }
    
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            result[i][j] %= MOD;
        }
    }
    
    return result;
}


int main(){
    cin >> d;
    while(d){
        if(d & 1){
            result = MultiPly(result, v);
        }
        v = MultiPly(v, v);
        d/=2;
    }
    
    
    cout << result[0][0] << "\n";
    return 0;
}
