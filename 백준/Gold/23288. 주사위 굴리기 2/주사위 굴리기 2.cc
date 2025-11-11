#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

int n, m, k;
int boards[1000][1000];
bool visited[1000][1000];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

enum class Direction {
	East,
	South,
	West,
	North,
};

class Dice {
public:
	int left = 4, right = 3;
	int dots[4] = { 2,1,5,6 };

	Direction direction = Direction::East;

	void RotateClockWise(bool isReverse = false) {
		if (isReverse) {
			int next = (static_cast<int>(direction) + 3) % 4;
			direction = static_cast<Direction>(next);
		}
		else {
			int next = (static_cast<int>(direction) + 1) % 4;
			direction = static_cast<Direction>(next);
		}
	}

	void Move() {
		if (direction == Direction::East) {
			// left => dots[1] => right => dots[3]
			int temp = dots[3];
			dots[3] = right;
			right = dots[1];
			dots[1] = left;
			left = temp;
		}
		else if (direction == Direction::West) {
			int temp = left;
			left = dots[1];
			dots[1] = right;
			right = dots[3];
			dots[3] = temp;
		}
		else if (direction == Direction::North) {
			int temp = dots[0];
			for (int i = 0; i < 3; i++) {
				dots[i] = dots[i + 1];
			}
			dots[3] = temp;
		}
		else {
			int temp = dots[3];
			for (int i = 3; i > 0; i--) {
				dots[i] = dots[i - 1];
			}
			dots[0] = temp;
		}
	}
};

int BFS(int sy, int sx) {
	memset(visited, false, sizeof(visited));
	int result = 0;
	queue<pair<int, int>> q;
	visited[sy][sx] = true;
	q.push({ sy, sx });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		result++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx] == true || boards[sy][sx] != boards[ny][nx]) continue;

			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}

	return result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> boards[i][j];
		}
	}

	int result = 0;
	int y = 0, x = 0;
	Dice* dice = new Dice();
	while (k--) {
		int direction = static_cast<int>(dice->direction);
		int ny = y + dy[direction];
		int nx = x + dx[direction];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
			ny = y - dy[direction];
			nx = x - dx[direction];
			direction = (direction + 2) % 4;
			dice->direction = static_cast<Direction>(direction);
		}
		dice->Move();
		y = ny, x = nx;
		result += boards[y][x] * BFS(y, x);
		int A = dice->dots[3];
		if (A > boards[y][x]) {
			dice->RotateClockWise();
		}
		else if (A < boards[y][x]) {
			dice->RotateClockWise(true);
		}
	}

	cout << result << "\n";
	return 0;
}