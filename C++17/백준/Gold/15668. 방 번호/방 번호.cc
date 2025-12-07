#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int numberSize = 0;
vector<long long> numbers;
vector<int> bits;
bool visited[10] = {false};

void InitNumbers(int len, long long number, int bit){
    if(len == numberSize){
        if(n >= number){
            numbers.emplace_back(number);
            bits.emplace_back(bit);
        }
        return;
    }
    
    
    for(int i=0;i<10;i++){
        if(visited[i] == true) continue;
        visited[i] = true;
        int next = (bit + (1 << i));
        InitNumbers(len + 1, (number * 10) + i, next);
        visited[i] = false;
    }
}

void solve(){
    for(int i=0;i<numbers.size();i++){
        long long num = numbers[i];
        int bit = bits[i];
        long long query = n - num;
        if(num == query) continue;
        
        auto it = lower_bound(numbers.begin(), numbers.end(), query);
        if(it != numbers.end() && (*it == query)){
            int index = (it - numbers.begin());
            int queryBit = bits[index];
            if((bit & queryBit) > 0) continue;
            
            
            cout << num << " + " << query << "\n";
            return;
        }
    }
    
    cout << "-1\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    int temp = n;
    while(temp != 0){
        temp /= 10;
        numberSize++;
        
        for(int i=1;i<10;i++){
            visited[i] = true;
            InitNumbers(1, i, (1 << i));
            visited[i] = false;
        }
    }
    
    //sort(numbers.begin(), numbers.end());
    solve();
    
    return 0;
}