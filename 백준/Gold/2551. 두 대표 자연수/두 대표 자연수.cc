#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<limits.h>
using namespace std;

long long n;
vector<long long> numbers;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    numbers.resize(n);
    
    long long a = n;
    long long b = 0;
    long long c = 0;
    
    for(int i=0;i<n;i++){
        cin >> numbers[i];
        b += numbers[i];
        c += numbers[i] * numbers[i];
    }
    
    b *= 2;
    
    sort(numbers.begin(), numbers.end());
    
    cout << numbers[(n - 1)/ 2] << " ";
    
    long long result = 0;
    long long prevValue = c - 1;
    for(long long i=1;i<=10010;i++){
        long long temp = a * i * i - b * i + c;
        if(prevValue <= temp){
            result = i - 1;
            break;
        }
        prevValue = temp;
    }
    cout << result << "\n";
    
    
    return 0;
}
