#include<iostream>
#include<algorithm>

using namespace std;

int n, l, m;
pair<int, int> fishies[100];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> l >> m;
	for (int i = 0; i < m; i++) {
		int y, x;
		cin >> y >> x;

		fishies[i] = { y, x };
	}

	int result = 1;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			int y = min(fishies[i].first, fishies[j].first);
			int x = min(fishies[i].second, fishies[j].second);

			int maxH = (l - 2) / 2;
			for (int h = 1; h <= maxH; h++) {
				int w = l / 2 - h;

				int cnt = 0;
				for (int k = 0; k < m; k++) {
					if (fishies[k].first < y || fishies[k].first > y + h ||
						fishies[k].second < x || fishies[k].second > x + w)
						continue;
					cnt++;
				}
				result = max(result, cnt);
			}
		}
	}

	cout << result << "\n";
}