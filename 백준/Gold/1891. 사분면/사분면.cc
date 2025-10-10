#include<iostream>
#include<string>

using namespace std;

int n;
string number;

long long y, x;
int dy[4] = {0,0,1,1};
int dx[4] = {1,0,0,1};

void solve(long long y, long long x){
    string s;
    
    long long bit = (1LL << (n - 1));
    if(y < 0 || x < 0 || y >= (1LL << n) || x >= (1LL << n))
    {
        cout << "-1\n";
        return;
    }
    
    for(int i=0;i<n;i++){
        int cy = (y & bit) > 0;
        int cx = (x & bit) > 0;
        
        bool isSuccess = false;
        for(int j=0;j<4;j++){
            if(cy == dy[j] && cx == dx[j]){
                s.push_back('1' + j);
                isSuccess = true;
                break;
            }
        }
        
        if(!isSuccess){
            cout << "-1";
            return;
        }
        
        bit >>= 1;
    }
    
    cout << s << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> number;
    for(int i=0;i<n;i++){
        int index = number[i] - '1';
        long long bit = (1LL << (n - i - 1));
        
        y += bit * dy[index];
        x += bit * dx[index];
    }
    
    long long moveX, moveY;
    cin >> moveX >> moveY;
    y -= moveY;
    x += moveX;
    solve(y, x);
    
    return 0;
}