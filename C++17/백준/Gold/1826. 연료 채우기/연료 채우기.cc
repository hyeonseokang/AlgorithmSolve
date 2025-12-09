#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n, l, p;
vector<pair<int, int>> stations;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	stations.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> stations[i].first >> stations[i].second;
	}

	sort(stations.begin(), stations.end());

	cin >> l >> p;

	int fuel = p;
	int result = 0;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int s = stations[i].first;
		int fuelAmount = stations[i].second;

		while (!pq.empty() && fuel < s) {
			result++;
			fuel += pq.top();
			pq.pop();
		}
		if (fuel < s) {
			result = -1;
			break;
		}

		pq.push(fuelAmount);
	}

	while (!pq.empty() && fuel < l) {
		result++;
		fuel += pq.top();
		pq.pop();
	}
	if (fuel < l) {
		result = -1;
	}
	cout << result << "\n";

	return 0;
}