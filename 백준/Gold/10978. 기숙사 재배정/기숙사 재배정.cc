#include<iostream>

using namespace std;

int t;
long long dp[21][2] = {0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[2][0] = 1;
	dp[2][1] = 0;

	for (int i = 3; i <= 20; i++) {
		dp[i][0] = dp[i - 1][0] * (i - 1) + dp[i - 1][1];
		dp[i][1] = i * dp[i - 1][0];
	}

	while(t--) {
		int n;
		cin >> n;

		cout << dp[n][0] << "\n";
	}
	return 0;
}