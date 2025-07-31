#include <iostream>
#include <algorithm> 
#include <vector>
#include <cmath>
#include <tuple>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

long long dp[1000001];

int main() {

    int n;
    cin >> n;
    
    dp[1] = 1;
    dp[2] = 2;
    for (int i=3; i<1000001; i++) {
        if (i%2) dp[i] = dp[i-1];
        else dp[i] = (dp[i-1]+dp[i/2])%1000000000;
    }
    cout << dp[n] << "\n";
    return 0;
}