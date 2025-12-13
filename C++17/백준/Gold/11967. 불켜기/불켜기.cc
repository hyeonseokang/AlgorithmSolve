#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int n, m;
int x, y, a, b;
typedef pair<int, int> PAIR;

vector<PAIR> graph[100][100];
bool visited[100][100][2] = { false };

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1,0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        x--, y--;
        a--, b--;
        graph[x][y].emplace_back(a, b);
    }

    visited[0][0][0] = true;
    visited[0][0][1] = true; 
    queue<PAIR> q;
    q.push({ 0,0 });
    int result = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (visited[ny][nx][0] == true) continue;

            if (visited[ny][nx][0] == false && visited[ny][nx][1] == true) {
                q.push({ ny, nx });
            }
            visited[ny][nx][0] = true;
        }

        for (const PAIR& p : graph[y][x]) {
            if (visited[p.first][p.second][1] == false && visited[p.first][p.second][0] == true) {
                q.push({ p.first, p.second });
            }
            if (visited[p.first][p.second][1] == false) {
                result++;
                visited[p.first][p.second][1] = true;
            }
        }
    }

    cout << result << "\n";
    return 0;
}