#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

int n, s;
int numbers[40];

vector<int> combinations;
long long result = 0;

void SetComb(int number, int l, int r, bool isInit = false, int c = 0) {
	if (l == r) {
		if (c == 0) return;
		if (number == s) result++;
		if (isInit) {
			combinations.emplace_back(number);
		}
		else {
			auto lowerIt = lower_bound(combinations.begin(), combinations.end(), s - number);
			auto upperIt = upper_bound(combinations.begin(), combinations.end(), s - number);
			if (lowerIt != combinations.end()) {
				result += (upperIt - lowerIt);
			}
		}
		return;
	}
	SetComb(number, l + 1, r, isInit, c);
	SetComb(number + numbers[l], l + 1, r, isInit, c + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	int half = n / 2;
	SetComb(0, 0, half, true, 0);
	sort(combinations.begin(), combinations.end());

	SetComb(0, half, n, false, 0);

	cout << result << "\n";

	return 0;
}