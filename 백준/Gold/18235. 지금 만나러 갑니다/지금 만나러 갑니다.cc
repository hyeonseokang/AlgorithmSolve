#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int n, a, b;

unordered_set<int> us[20];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> a >> b;
	us[0].insert(a - 1);
	us[0].insert(b - 1);
	int result = -1;
	for (int i = 0; i < 19; i++) {
		int step = (1 << i);
		unordered_set<int>& nextSet = us[i + 1];
		for (int num : us[i]) {
			int left = num - step;
			int right = num + step;
			if (left >= 0) {
				if (nextSet.find(left) != nextSet.end()) {
					result = i + 1;
					break;
				}
				nextSet.insert(left);
			}
			if (right < n) {
				if (nextSet.find(right) != nextSet.end()) {
					result = i + 1;
					break;
				}
				nextSet.insert(right);
			}
		}
		if (result != -1) break;
	}

	cout << result << "\n";
	return 0;
}