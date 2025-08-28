#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<unordered_map>

using namespace std;

int n;
vector<int> numbers;

bool isPrime[500001] = {false};
long long results[500001] = {0};
unordered_map<int, int> um;

void Init(){
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2;i<=500000;i++){
        if(isPrime[i] == false) continue;
        
        for(int j = i*2 ;j<=500000;j+=i){
            isPrime[j] = false;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Init();
    cin >> n;
    results[0] = 1;
    
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        um[num]++;
    }
    
    for(pair<int, int> p: um){
        int num = p.first;
        int used = p.second;
        if(num == 0){
            continue;
        }
        
        for(int i = 10000 * n;i>=1;i--){
            for(int j=1;j<=used;j++){
                int usedNum = num * j;
                if(i >= usedNum){
                    results[i] += results[i - usedNum];
                }
            }
        }
    }
    
    
    int zeroCount = um[0];
    long long result = 0;
    for(int i=1;i<=500000;i++){
        if(isPrime[i] == true){
            result += results[i];
        }
    }
    
    cout << result * (zeroCount + 1) << "\n";
    
    return 0;
}
