#include<iostream>
#include<algorithm>

using namespace std;


int w, n;
int numbers[5000];
bool isPossible[800000] = {false};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> w >> n;
    for(int i=0;i<n;i++){
        cin >> numbers[i];
    }
    sort(numbers, numbers + n);
    
    bool isSuccess = false;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int weight = numbers[i] + numbers[j];
            if(weight >= w) break;
            
            if(isPossible[w - weight] == true){
                cout << "YES\n";
                return 0;
            }
        }
        
        for(int j=0;j<i;j++){
            int weight = numbers[i] + numbers[j];
            if(weight >= w) break;
            isPossible[weight] = true;
        }
    }
    
    cout << "NO\n";
    return 0;
}
