#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
 
unordered_map<ll, ll> m;
ll N, p, q, x, y;
 
ll solve(ll n) {
    if (n <= 0) return 1LL;
    if (m.find(n) != m.end()) return m[n];
    return m[n] = solve(n / p - x) + solve(n / q - y);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> N >> p >> q >> x >> y;
    cout << solve(N) << '\n';
 
    return 0;
}
