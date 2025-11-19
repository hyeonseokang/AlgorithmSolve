#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PAIR;

int n, m, k;
bool visited[1001] = { false };
vector<vector<PAIR>> graph;
priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;

int solve() {
	int result = 0;
	while (!pq.empty()) {
		int s = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (visited[s])
			continue;
		visited[s] = true;
		result += cost;

		const vector<PAIR>& v = graph[s];
		for (int i = 0; i < v.size(); i++) {
			int e = v[i].first;
			if (visited[e] == true) continue;

			pq.push({ v[i].second, e });
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;

	graph.resize(n + 1);
	
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		visited[num] = true;
	}

	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		if (visited[a] == true) {
			pq.push({ cost, b });
		}
		if (visited[b] == true) {
			pq.push({ cost, a });
		}

		graph[a].emplace_back(b, cost);
		graph[b].emplace_back(a, cost);
	}

	cout << solve() << "\n";
	return 0;
}