#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

int n;
int cnts[4] = { 0 };
int numberCnt[3][3] = { 0 };
vector<int> numbers;

int solve(int lNum, int rNum) {
	int lCnt = cnts[lNum], rCnt = cnts[rNum];
	memset(numberCnt, 0, sizeof(numberCnt));

	for (int i = 0; i < lCnt; i++) {
		if(numbers[i] == lNum) numberCnt[0][0]++;
		else if(numbers[i] == rNum) numberCnt[0][2]++;
		else numberCnt[0][1]++;
	}

	for (int i = lCnt; i < n - rCnt; i++) {
		if (numbers[i] == lNum) numberCnt[1][0]++;
		else if (numbers[i] == rNum) numberCnt[1][2]++;
		else numberCnt[1][1]++;
	}

	for (int i = n - 1; i >=  n - rCnt; i--) {
		if (numbers[i] == lNum) numberCnt[2][0]++;
		else if (numbers[i] == rNum) numberCnt[2][2]++;
		else numberCnt[2][1]++;
	}

	int result = 0;
	result += min(numberCnt[0][2], numberCnt[2][0]);
	result += min(numberCnt[0][1], numberCnt[1][0]);
	result += min(numberCnt[2][1], numberCnt[1][2]);

	int diff = abs(numberCnt[0][2] - numberCnt[2][0]);
	result += diff * 2;


	return result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	numbers.resize(n);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		numbers[i] = num;
		cnts[num]++;
	}

	int result = INT_MAX;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if (i != j) {
				result = min(result, solve(i, j));
			}
		}
	}
	cout << result << "\n";
	return 0;
}