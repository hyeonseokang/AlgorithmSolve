#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n;
int result = 10000000;
typedef pair<int, int> PAIR;
string room[50];
int dists[50][50] = { 0 };
typedef pair<int, pair<PAIR, PAIR>> Node;

PAIR s, e;

bool IsOutSide(int y, int x) {
	return y < 0 || x < 0 || y >= n || x >= n;
}

int solve() {
	queue <Node> pq;
	pq.push({ 0, {{1, 0}, {s}} });
	pq.push({ 0, {{-1, 0}, {s}} });
	pq.push({ 0, {{0, 1}, {s}} });
	pq.push({ 0, {{0, -1}, {s}} });

	while (!pq.empty()) {
		int cnt = pq.front().first;
		int dy = pq.front().second.first.first;
		int dx = pq.front().second.first.second;
		int y = pq.front().second.second.first;
		int x = pq.front().second.second.second;
		pq.pop();
		y += dy, x += dx;
		while (!IsOutSide(y, x)) {
			if (room[y][x] == '*')
				break;
			if (y == e.first && x == e.second)
				return cnt;
			else if (room[y][x] == '!') {
				if (dists[y][x] == 0 || cnt + 1 < dists[y][x]) {
					dists[y][x] = cnt + 1;
					pq.push({ cnt + 1, {{dx, dy}, {y, x}} });
					pq.push({ cnt + 1, {{-dx, -dy}, {y, x}} });
				}
			}

			y += dy;
			x += dx;
		}
	}

	return -1;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	s.first = -1, e.first = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> room[i];
		for (int j = 0; j < n; j++) {
			if (room[i][j] == '#') {
				if (s.first == -1) {
					s = { i, j };
				}
				else {
					e = { i, j };
				}
			}
		}
	}
	result = solve();
	cout << result << "\n";

	return 0;
}