#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>

using namespace std;

int n, m;
int heights[50][50] = { 0 };
bool visited[50][50] = { false };

typedef pair<int, int> PAIR;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool IsOutSide(int y, int x) {
	return y < 0 || x < 0 || y >= n || x >= m;
}

void BFS(int h, int sy, int sx) {
	visited[sy][sx] = true;
	queue<PAIR> q;
	q.push({ sy, sx });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (IsOutSide(ny, nx)) continue;
			if (visited[ny][nx] == true) continue;

			if (heights[ny][nx] >= heights[y][x]) {
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	vector<PAIR> startPos;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			heights[i][j] = s[j] - '0';
			if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
				startPos.emplace_back(i, j);
			}
		}
	}

	int result = 0;
	for (int h = 1; h < 10; h++) {
		memset(visited, false, sizeof(visited));
		for (const PAIR& p : startPos) {
			int height = heights[p.first][p.second];
			if (height <= h && visited[p.first][p.second] == false) {
				BFS(h, p.first, p.second);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == false && heights[i][j] < h) {
					result++;
					heights[i][j] = h;
				}
			}
		}
	}
	cout << result << "\n";

	return 0;
}