#include<iostream>

using namespace std;

int n;
long long dp[10001];
const int MOD = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 1;

	cin >> n;
	for (int i = 4; i <= n; i += 2) {
		dp[i] = 0;
		for (int j = 1; j < i; j += 2) {
			int a = j - 1;
			int b = i - (j - 1) - 2;

			dp[i] += (dp[a] * dp[b]) % MOD;
			dp[i] %= MOD;
		}
	}
	
	cout << dp[n] << "\n";
	return 0;
}