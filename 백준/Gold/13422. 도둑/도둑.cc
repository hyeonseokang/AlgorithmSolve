#include<iostream>
#include<vector>

using namespace std;

int t;
int n, m, k;
vector<int> numbers;

bool IsSecurity(int sums){
    return sums >= k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        numbers.resize(n);
        for(int i=0;i<n;i++){
            cin >> numbers[i];
        }
        
        int sums = 0;
        for(int i=0;i<m;i++){
            sums += numbers[i];
        }
        
        int result = 0;
        
        if(n == m){
            if(!IsSecurity(sums))
                result++;
        }
        else{
            for(int i=0;i<n;i++){
                sums -= numbers[i];
                sums += numbers[(i + m) % n];
                
                if(!IsSecurity(sums))
                    result++;
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}
