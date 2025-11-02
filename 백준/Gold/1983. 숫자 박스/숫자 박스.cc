#include<iostream>
#include<cstring>
#include<vector>
#include<limits.h>

using namespace std;
int n;
int dp[401][401][401];

vector<int> numbers1;
vector<int> numbers2;
int size1, size2;

int solve(int len, int a, int b) {
	if (a == size1 || b == size2)
		return 0;

	int& ret = dp[len][a][b];
	if (ret != -50000)
		return ret;

	int remain = n - len;
	int remainA = size1 - a;
	int remainB = size2 - b;

	ret = solve(len + 1, a + 1, b + 1) + numbers1[a] * numbers2[b];
	if (remain > remainB) {
		ret = max(ret, solve(len + 1, a + 1, b));
	}
	if (remain > remainA) {
		ret = max(ret, solve(len + 1, a, b + 1));
	}


	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				dp[i][j][k] = -50000;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num != 0) {
			numbers1.emplace_back(num);
		}
	}
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num != 0) {
			numbers2.emplace_back(num);
		}
	}
	size1 = numbers1.size();
	size2 = numbers2.size();

	int result = solve(0, 0, 0);
	cout << result << "\n";

	return 0;
}