#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

int sticks[100001] = { 0 };
int n, q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	int maxNum = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		sticks[num]++;

	}


	cin >> q;
	vector<int> resultNum(q);
	for (int i = 0; i < q; i++) {
		int num;
		cin >> num;
		resultNum[i] = num;
		maxNum = max(maxNum, num);
	}


	for (int i = 1; i <= maxNum/2; i++) {
		for (int j = i * 2; j <= maxNum; j += i) {
			sticks[j] += sticks[i];
		}
	}

	for (int i = 0; i < q; i++) {
		cout << sticks[resultNum[i]] << " ";
	}

	return 0;
}