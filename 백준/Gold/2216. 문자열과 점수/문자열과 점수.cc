#include<iostream>
#include<string>
#include<cstring>
#include<limits.h>
#include<algorithm>

using namespace std;

int dp[3001][3001] = { 0 };
int a, b, c;
string s1, s2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> b >> c;
	cin >> s1 >> s2;
	s1 = " " + s1;
	s2 = " " + s2;

	dp[0][0] = 0;
	for (int i = 1; i < s1.size(); i++) {
		dp[i][0] = b * i;
	}
	for (int i = 1; i < s2.size(); i++) {
		dp[0][i] = b * i;
	}

	for (int i = 1; i < s1.size(); i++) {
		for (int j = 1; j < s2.size(); j++) {
			int& ret = dp[i][j];
			if (s1[i] == s2[j]) {
				ret = dp[i - 1][j - 1] + a;
			}
			else {
				ret = dp[i - 1][j - 1] + c;
				ret = max(ret, dp[i - 1][j] + b);
				ret = max(ret, dp[i][j - 1] + b);
			}
		}
	}

	cout << dp[s1.size() - 1][s2.size() - 1] << "\n";

	return 0;
}