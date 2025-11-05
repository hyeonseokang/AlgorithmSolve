#include<iostream>
#include<string>
#include<cstring>
#include<limits.h>
#include<algorithm>

using namespace std;

int dp[3000][3000];
bool visited[3000][3000] = { false };
int a, b, c;
string s1, s2;

int solve(int idx1, int idx2) {
	if (idx1 == s1.size() && idx2 == s2.size()) {
		return 0;
	}
	else if (idx1 == s1.size()) {
		return (s2.size() - idx2) * b;
	}
	else if (idx2 == s2.size()) {
		return (s1.size() - idx1) * b;
	}

	int& ret = dp[idx1][idx2];
	if (visited[idx1][idx2] == true) {
		return ret;
	}
	visited[idx1][idx2] = true;
	ret = INT_MIN;
	ret = max(ret, solve(idx1 + 1, idx2) + b);
	ret = max(ret, solve(idx1, idx2 + 1) + b);
	int temp = s1[idx1] == s2[idx2] ? a : c;
	ret = max(ret, solve(idx1 + 1, idx2 + 1) + temp);

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));

	cin >> a >> b >> c;
	cin >> s1 >> s2;

	cout << solve(0, 0) << "\n";

	return 0;
}