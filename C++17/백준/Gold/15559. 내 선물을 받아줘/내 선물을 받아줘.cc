#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> parents;

int Find(int x) {
	int parent = parents[x];
	if (x == parent || parent == -1) {
		return parent;
	}

	return parents[x] = Find(parent);
}

void Merge(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa < pb) {
		parents[pb] = pa;
	}
	else {
		parents[pa] = pb;
	}
}

int n, m;
string board[1000];
bool visited[1000][1000] = { false };

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int GetDirectionIndex(char c) {
	if (c == 'S') return 0;
	else if(c == 'E') return 1;
	else if(c == 'N') return 2;
	else return 3;
}

void DFS(int sy, int sx) {
	visited[sy][sx] = true;

	int dir = GetDirectionIndex(board[sy][sx]);
	int ny = sy + dy[dir];
	int nx = sx + dx[dir];

	if (ny < 0 || nx < 0 || ny >= n || nx >= m)
		return;

	Merge(ny * m + nx, sy * m + sx);
	if (visited[ny][nx] == false) {
		DFS(ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	parents.resize(n * m);
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			int index = i * m + j;
			parents[index] = index;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == false) {
				DFS(i, j);
			}
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int index = i * m + j;
			int parent = Find(index);
			if (parent != -1) {
				result++;
				parents[parent] = -1;
			}
		}
	}

	cout << result << "\n";
	return 0;
}