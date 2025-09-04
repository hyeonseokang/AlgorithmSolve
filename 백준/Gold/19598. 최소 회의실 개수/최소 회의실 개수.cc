#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> meeting(n);
	for (int i = 0; i < n; i++) {
		cin >> meeting[i].first >> meeting[i].second;
	}

	sort(meeting.begin(), meeting.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(meeting[0].second);
	int blankCnt = 0;

	for (int i = 1; i < n; i++) {
		int s = meeting[i].first;
		int e = meeting[i].second;

		while (!pq.empty() && pq.top() <= s) {
			pq.pop();
			blankCnt++;
		}

		if (blankCnt > 0)
			blankCnt--;

		pq.push(e);
	}

	cout << pq.size() + blankCnt << "\n";

	return 0;
}