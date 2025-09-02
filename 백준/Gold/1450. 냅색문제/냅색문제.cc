#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, c;
int weights[30];
vector<int> combinations;
long long result = 0;

// 2 1
// 1 1

// 0 1

// 0일때 c - sums = 1
// 1일때 c - sums = 0

void Init(int l, int r, int sums, bool isInit = false) {
	if (sums > c) return;

	if (l == r) {
		if (isInit) {
			combinations.emplace_back(sums);
		}
		else {
			if (c - sums == 0) {
				result++;
				return;
			}
			auto it = upper_bound(combinations.begin(), combinations.end(), c - sums);
			result += (it - combinations.begin());
		}
		return;
	}

	Init(l + 1, r, sums, isInit);

	int nSums = sums + weights[l];
	Init(l + 1, r, nSums, isInit);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> weights[i];
	}

	int half = n / 2;
	Init(0, half, 0, true);
	sort(combinations.begin(), combinations.end());
	Init(half, n, 0, false);

	cout << result << "\n";

	return 0;
}