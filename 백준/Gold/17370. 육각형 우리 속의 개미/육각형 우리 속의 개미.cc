#include<iostream>

using namespace std;

bool visited[45][45] = { false };

int n;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int solve(int len, int dir, int y, int x) {
	int l = 1;
	int r = 3;
	if (dy[dir] == 0) {
		if (dir == 1) {
			l = 1;
		}
		else {
			l = 3;
		}

		if ((x  + ((y + 1)% 2)) % 2 == 0) {
			r = 2;
		}
		else {
			r = 0;
		}
	}

	if (len + 1 == n) {
		int result = 0;
		if (visited[y + dy[l]][x + dx[l]] == true)
			result++;
		if (visited[y + dy[r]][x + dx[r]] == true)
			result++;

		return result;
	}

	int result = 0;
	int ny = y + dy[l];
	int nx = x + dx[l];

	if (visited[ny][nx] == false) {
		visited[ny][nx] = true;
		result += solve(len + 1, l, ny, nx);
		visited[ny][nx] = false;
	}
	ny = y + dy[r];
	nx = x + dx[r];
	if (visited[ny][nx] == false) {
		visited[ny][nx] = true;
		result += solve(len + 1, r, ny, nx);
		visited[ny][nx] = false;
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	visited[22][22] = true;
	visited[21][22] = true;
	int result = solve(0, 0, 21, 22);
	cout << result << "\n";

	return 0;
}