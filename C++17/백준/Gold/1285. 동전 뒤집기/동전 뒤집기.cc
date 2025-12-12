#include<iostream>
#include<string>
#include<algorithm>
#include<limits.h>
using namespace std;

int n;
string s[20];

int bits[20] = { 0 };
int mask;
int result = INT_MAX;

void solve(int len) {
	if (len == n) {
		int allCnt = 0;
		for (int i = 0; i < n; i++) {
			int bit = (1 << i);
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if ((bits[j] & bit) > 0) {
					cnt++;
				}
			}

			allCnt += min(cnt, n - cnt);
		}
		result = min(result, allCnt);
		return;
	}

	int bit = bits[len];
	solve(len + 1);
	bits[len] = ~bit;
	bits[len] &= mask;
	solve(len + 1);
	bits[len] = bit;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	mask = (1 << n) - 1;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < n; j++) {
			if (s[i][j] == 'T') {
				bits[i] |= (1 << j);
			}
		}
	}
	solve(0);
	cout << result << "\n";

	return 0;
}