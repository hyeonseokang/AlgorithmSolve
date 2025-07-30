#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<cmath>

using namespace std;

int GCD(int a, int b){
    if(b==0)
        return a;
    
    return GCD(b, a % b);
}

vector<int> primes;
bool isPrime[1000001] = {false};
int n;
int numbers[100];
unordered_map<int, int> factors;
unordered_map<int, int> numberFactors[100];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(isPrime, true, sizeof(isPrime));
    
    for(int i=2;i<1000001;i++){
        if(isPrime[i] == false) continue;
        primes.emplace_back(i);
        for(int j=i*2;j<1000001;j+=i){
            isPrime[j] = false;
        }
    }
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> numbers[i];
        
        int number = numbers[i];
        for(int j=0;j<primes.size();j++){
            if(number == 1) break;
            
            int prime = primes[j];
            
            while(number % prime == 0){
                number /= prime;
                factors[prime]++;
                numberFactors[i][prime]++;
            }
        }
    }
    
    int result = 1;
    for(auto& p:factors){
        int factor = p.first;
        int exp = p.second;
        
        exp /= n;
        if(exp != 0){
            result *= pow(factor, exp);
        }
        factors[factor] = exp;
    }
    
    int cnt = 0;
    for(auto& p:factors){
        int factor = p.first;
        int exp = p.second;
        
        for(int i=0;i<n;i++){
            if(numberFactors[i][factor] < exp){
                cnt += (exp - numberFactors[i][factor]);
            }
        }
    }
    
    
    cout << result << " " << cnt << "\n";
    
    return 0;
}
