#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>

using namespace std;

typedef pair<int, int> PAIR;
int t;
int n, m;
string boards[1001];
bool visited[1001][1001] = { false };
int fireMap[1001][1001] = { 0 };
PAIR player;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool IsFires(int y, int x, int cost) {
	if (fireMap[y][x] == 0)
		return false;
	if (fireMap[y][x] <= cost)
		return true;

	return false;
}

int solve() {
	queue<pair<PAIR, int>> q;
	while (!q.empty()) {
		q.pop();
	}

	memset(visited, false, sizeof(visited));

	q.push({ player , 1});
	visited[player.first][player.second] = true;

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cost = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
				return cost;
			}

			if (visited[ny][nx] || boards[ny][nx] == '#') {
				continue;
			}

			if (IsFires(ny, nx, cost + 1)) {
				continue;
			}

			visited[ny][nx] = true;
			q.push({ {ny, nx}, cost + 1 });
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		memset(fireMap, 0, sizeof(fireMap));
		cin >> m >> n;
		queue<PAIR> q;
		while (!q.empty()) {
			q.pop();
		}

		for (int i = 0; i < n; i++) {
			cin >> boards[i];
			for (int j = 0; j < m; j++) {
				if (boards[i][j] == '@') {
					player = { i, j };
				}
				else if (boards[i][j] == '*') {
					fireMap[i][j] = 1;
					q.push({ i, j });
				}
			}
		}

		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			int dist = fireMap[y][x];
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (fireMap[ny][nx] != 0 || boards[ny][nx] == '#') continue;

				q.push({ ny, nx });
				fireMap[ny][nx] = dist + 1;
			}
		}

		int result = solve();
		if (result == -1) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			cout << result << "\n";
		}
	}


	return 0;
}
