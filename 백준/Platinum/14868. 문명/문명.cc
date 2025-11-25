#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct Data {
	int y, x;
};


int n, k, m;
int _map[2005][2005];
int p[100005];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int _find(int x) {
	if (p[x] == x)return x;
	return p[x] = _find(p[x]);
}
bool _union(int x, int y) {
	x = _find(x);
	y = _find(y);
	if (x == y)return false;
	p[x] = y;
	return true;
}
bool Range(int y, int x) {
	if (y<1 || x<1 || y>n || x>n)return false;
	return true;
}
queue<Data>q;
int main() {
	for (int i = 0; i < 100001; i++)p[i] = i;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		_map[a][b] = i + 1;
		q.push({ a,b });

		for (int j = 0; j < 4; j++) {
			int ny = a + dy[j];
			int nx = b + dx[j];
			if (Range(ny, nx) && _map[ny][nx] != 0) {
				if (_union(_map[ny][nx], _map[a][b])) {
					m++;
				}
			}
		}
	}
	int t = 0;

	while (1) {
		if (m == k - 1)break;
		t++;
		int _size = q.size();
		for (int s = 0; s < _size; s++) {
			Data now = q.front();	q.pop();


			for (int i = 0; i < 4; i++) {
				int ny = now.y + dy[i];
				int nx = now.x + dx[i];

				if (Range(ny, nx)) {
					if (_map[ny][nx] == 0) {
						_map[ny][nx] = _map[now.y][now.x];

						for (int j = 0; j < 4; j++) {
							int nny = ny + dy[j];
							int nnx = nx + dx[j];
							if (Range(nny, nnx) && _map[ny][nx] != _map[nny][nnx] && _map[nny][nnx] != 0) {
								if (_union(_map[ny][nx], _map[nny][nnx])) {
									m++;
								}
							}
						}
						q.push({ ny,nx });
					}
				}
			}
		}
	}
	cout << t << endl;
	return 0;
}