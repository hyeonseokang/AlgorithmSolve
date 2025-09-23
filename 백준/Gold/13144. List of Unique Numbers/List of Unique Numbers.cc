#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;
int n;
vector<int> numbers;
unordered_map<int, int> um;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	numbers.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	long long result = 0;
	int l = 0, r = 0;
	int cnt = 0;
	for (; r < numbers.size(); r++) {
		um[numbers[r]]++;
		if(um[numbers[r]] == 1) {
			cnt++;
		}
		else if(um[numbers[r]] == 2) {
			cnt--;
		}

		int len = r - l + 1;
		while (l < r) {
			if (len == cnt) {
				break;
			}
			um[numbers[l]]--;
			if (um[numbers[l]] == 1) {
				cnt++;
			}
			else if(um[numbers[l]] == 0) {
				cnt--;
			}

			l++;
			len = r - l + 1;
		}

		if (len == cnt) {
			result += len;
		}
	}

	cout << result << '\n';

	return 0;
}