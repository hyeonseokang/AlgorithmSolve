#include<iostream>

using namespace std;

int t;
long long dp[21] = {0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	dp[1] = 0;
	dp[2] = 1;

	for (int i = 3; i <= 20; i++) {
		int prev = i - 1;
		dp[i] = dp[prev] * (prev) + dp[i - 2] * (prev);
	}

	while(t--) {
		int n;
		cin >> n;

		cout << dp[n] << "\n";
	}
	return 0;
}