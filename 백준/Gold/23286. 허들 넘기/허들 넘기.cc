#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, t;
int graph[301][301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	memset(graph, -1, sizeof(graph));

	cin >> n >> m >> t;
	for (int i = 0; i < m; i++) {
		int u, v, h;
		cin >> u >> v >> h;

		graph[u][v] = h;
	}

	for (int k = 1; k <= n; k++) {
		for (int j = 1; j <= n; j++) {
			for (int i = 1; i <= n; i++) {
				if (i == j || j == k || i == k) continue;

				if (graph[i][k] == -1 || graph[k][j] == -1) continue;
				int temp = max(graph[i][k], graph[k][j]);

				if (graph[i][j] == -1 || graph[i][j] > temp) {
					graph[i][j] = temp;
				}
			}
		}
	}

	for (int i = 0; i < t; i++) {
		int s, e;
		cin >> s >> e;

		cout << graph[s][e] << "\n";
	}

	return 0;
}