#include <iostream>

using namespace std;

const long long MOD = 1000000007;

int n, k;
long long r;


long long Pow(long long m) {
    m %= MOD;
    return m * m % MOD;
}

long long fac(long long x) {
    if (x == 1 || x == 0) return 1;
    return (fac(x - 1) % MOD) * x % MOD ;
}

long long prime(long long p) {
    if (p == 1) return r;
    if (p % 2 > 0) return prime(p - 1) * r % MOD;
    return Pow(prime(p / 2)) % MOD;
}
 
int main(void) {
    cin >> n >> k;
    r = fac(n-k) * fac(k) % MOD;
    long long fib_n = fac(n) % MOD;
    cout << (fib_n * prime(MOD-2) % MOD);
}
