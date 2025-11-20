#include<iostream>
#include<string>

using namespace std;

int n, m, k;
string boards[300];
bool winBoards[300][300] = { false };

bool IsOutSide(int y, int x) {
	return x < 0 || y < 0 || y >= n || x >= m;
}

bool IsWin(int y, int x) {
	if (y < n - 1 && boards[y + 1][x] != '#') {
		if (winBoards[y + 1][x] == true) {
			return false;
		}
	}
	if (x < m - 1 && boards[y][x + 1] != '#') {
		if (winBoards[y][x + 1] == true) {
			return false;
		}
	}
	
	int i = 1;
	while (i <= k) {
		int ny = y + i;
		int nx = x + i;
		if (IsOutSide(ny, nx))
			break;
		if (boards[ny][nx] != '#') {
			if (winBoards[ny][nx] == true) {
				return false;
			}
		}
		
		i++;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> boards[i];
	}

	int y = n - 1;
	int x = m - 1;
	while (y > 0 && x > 0) {
		for (int i = y; i >= 0; i--) {
			winBoards[i][x] = IsWin(i, x);
		}
		for (int i = x-1; i >= 0; i--) {
			winBoards[y][i] = IsWin(y, i);
		}
		y--;
		x--;
	}
	winBoards[0][0] = IsWin(0, 0);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int y, x;
		cin >> y >> x;
		y--;
		x--;

		if (!winBoards[y][x]) {
			cout << "First\n";
		}
		else {
			cout << "Second\n";
		}
	}
	return 0;
}