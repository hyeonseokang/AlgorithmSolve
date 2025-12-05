#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, a, b;

typedef pair<int, int> PAIR;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> a >> b;
	priority_queue<PAIR, vector<PAIR>, greater<PAIR>> q;
	q.push({ 0, a - 1 });
	q.push({ 0, b - 1 });
	int result = -1;

	while (!q.empty()) {
		int bit = q.top().first;
		int s = q.top().second;
		int step = (1 << bit);
		q.pop();

		if (!q.empty()) {
			if (s == q.top().second && bit == q.top().first) {
				result = bit;
				break;
			}
		}


		int left = s - step;
		int right = s + step;

		if (left >= 0) {
			q.push({ bit + 1, left});
		}
		if (right < n) {
			q.push({ bit + 1, right });
		}
	}
	cout << result << "\n";
	return 0;
}