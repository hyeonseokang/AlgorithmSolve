#include<iostream>
#include<cstring>
#include<limits.h>

using namespace std;

int people[5] = { 0 };
int worlds[20][20];
int test[20][20] = { 0 };
int n;

int solve(int x, int y, int d1, int d2) {
	memset(people, 0, sizeof(people));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int index = 4;
			if (j <= x + d1 && i < y - max(j - x, 0)) {
				index = 0;
			}
			else if (j > x + d1 && i < (y - d1) + min(j - (x + d1), d2 + 1)) {
				index = 1;
			}
			else if (j < x + d2 && i > y + max(j - x, -1)) {
				index = 2;
			}
			else if (j >= x + d2 && i > (y + d2) - min(j - (x + d2), d1)) {
				index = 3;
			}
			
			people[index] += worlds[i][j];
			test[i][j] = index;
		}
	}

	int maxPeople = -1;
	int minPeople = INT_MAX;
	for (int i = 0; i < 5; i++) {
		maxPeople = max(maxPeople, people[i]);
		minPeople = min(minPeople, people[i]);
	}
	
	return maxPeople - minPeople;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	solve(1, 4, 3, 2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> worlds[i][j];
		}
	}
	int result = INT_MAX;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			for (int d1 = 1; d1 < n; d1++) {
				if (y - d1 < 0) break;
				for (int d2 = 1; d2 < n; d2++) {
					if (x + d1 + d2 >= n) break;
					if (y + d2 >= n) break;

					result = min(result, solve(x, y, d1, d2));
				}
			}
		}
	}

	cout << result << "\n";

	return 0;
}