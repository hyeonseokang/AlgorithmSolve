#include<iostream>
#include<cstring>

using namespace std;

int dp[51][51][51][51];
const int MOD = 1000000007;

int solve(int s, int a, int b, int c){
	if (a + b + c < s)
		return 0;
	if (s == 0) {
		if (a > 0 || b > 0 || c > 0)
			return 0;
		else
			return 1;
	}

	int& ret = dp[s][a][b][c];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = 0; i <= min(a, 1); i++) {
		for (int j = 0; j <= min(b, 1); j++) {
			for (int k = 0; k <= min(c, 1); k++) {
				if (i == 0 && j == 0 && k == 0)
					continue;
				ret += solve(s - 1, a - i, b - j, c - k);
				ret %= MOD;
			}
		}
	}

	return ret % MOD;
}
int  main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));
	int s, a, b, c;
	cin >> s >> a >> b >> c;
	int result = solve(s, a, b, c);
	cout << result << "\n";

	return 0;
}