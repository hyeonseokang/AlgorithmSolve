#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int n, m, k;
int numbers[50];
int results[50] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> numbers[i];
	}

	int l = 0;
	int r = 1000001;
	int result = l;

	while (l <= r) {
		int mid = (l + r) / 2;

		int cnt = 1;
		int lastPos = numbers[0];
		for (int i = 1; i < k; i++) {
			int diff = numbers[i] - lastPos;

			if (mid <= diff) {
				cnt++;
				lastPos = numbers[i];
			}
		}

		if (cnt < m) {
			r = mid - 1;
		}
		else {
			result = mid;
			l = mid + 1;
		}
	}

	results[0] = 1;
	int cnt = 1;
	int lastPos = numbers[0];
	for (int i = 1; i < k; i++) {
		int diff = numbers[i] - lastPos;
		if (cnt < m && result <= diff) {
			cnt++;
			lastPos = numbers[i];
			results[i] = 1;
		}
	}

	for (int i = 0; i < k; i++) {
		cout << results[i];
	}
	cout << "\n";

	return 0;
}