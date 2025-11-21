#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

vector<int> heights;
vector<pair<int, int>> nearBulidings;
vector<int> cnts;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	heights.resize(n);
	nearBulidings.resize(n);
	cnts.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> heights[i];
	}

	stack<pair<int, int>> st;
	for (int i = 0; i < n; i++) {
		int h = heights[i];

		while (!st.empty() && st.top().first <= h) {
			st.pop();
		}

		if (!st.empty()) {
			nearBulidings[i] = { i - st.top().second, st.top().second };
		}
		else {
			nearBulidings[i] = { INT_MAX, INT_MAX };
		}

		cnts[i] += st.size();
		st.push({h, i});
	}

	while (!st.empty()) {
		st.pop();
	}

	for (int i = n-1; i >= 0; i--) {
		int h = heights[i];

		while (!st.empty() && st.top().first <= h) {
			st.pop();
		}

		if (!st.empty()) {
			int dist = st.top().second - i;
			if (dist < nearBulidings[i].first) {
				nearBulidings[i] = { dist, st.top().second };
			}
		}
		cnts[i] += st.size();
		st.push({h, i});
	}

	for (int i = 0; i < n; i++) {
		cout << cnts[i];
		if (cnts[i] > 0) {
			cout << " " << nearBulidings[i].second + 1;
		}
		cout << "\n";
	}
	return 0;
}