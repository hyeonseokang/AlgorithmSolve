#include <iostream>
#include <vector>
using namespace std;

int popcount_ull(unsigned long long x) {
    int cnt = 0;
    while (x) {
        x &= (x - 1);
        ++cnt;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    vector<long long> v(n);
    for (long long i = 0; i < n; ++i) cin >> v[i];

    long long result = 0;

    for (unsigned long long mask = 1; mask < (1ULL << n); ++mask) {
        long long cur = 1;
        for (long long j = 0; j < n; ++j) {
            if (mask & (1ULL << j)) {
                cur *= v[j];
            }
        }
        if (popcount_ull(mask) & 1) result += m / cur;
        else result -= m / cur;
    }

    cout << result << '\n';
    return 0;
}
