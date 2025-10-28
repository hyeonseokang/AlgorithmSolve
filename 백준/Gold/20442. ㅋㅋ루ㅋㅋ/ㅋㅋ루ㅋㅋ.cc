#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string s;
vector<int> rSums;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;
	rSums.resize(s.size(), 0);
	int rSumCnt = 0;
	for (int i = 0; i < s.size(); i++) {
		const char& c = s[i];
		if (c == 'R') {
			rSumCnt++;
		}
		rSums[i] = rSumCnt;
	}

	int result = rSums.back();
	int l = 0;
	int r = s.size() - 1;
	int kCnt = 0;
	while (l < r) {
		while (l < r && s[l] == 'R') {
			l++;
		}
		while (l < r && s[r] == 'R') {
			r--;
		}
		kCnt += 2;
		int rCnt = rSums[r] - rSums[l];
		if (rCnt > 0) {
			result = max(result, kCnt + rSums[r] - rSums[l]);
		}
		l++;
		r--;
	}

	cout << result << "\n";
	return 0;
}