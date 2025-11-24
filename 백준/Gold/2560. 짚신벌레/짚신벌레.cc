#include<iostream>
#include<queue>

using namespace std;

int a, b, d, n;
queue<int> baby;
queue<int> adult;
queue<int> dead;
int adultCnt = 0;

const int MOD = 1000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> b >> d >> n;
	for (int i = 1; i < a; i++) {
		baby.push(0);
	}
	baby.push(1);
	for (int i = 1; i < b; i++) {
		adult.push(0);
	}
	adult.push(1);
	for (int i = 1; i < d; i++) {
		dead.push(0);
	}
	dead.push(1);

	int result = 1;
	for (int i = 1; i <= n; i++) {
		adultCnt += baby.front();
		adultCnt %= MOD;
		adultCnt += MOD - adult.front();
		adultCnt %= MOD;
		result += MOD - dead.front();
		result %= MOD;

		baby.pop();
		adult.pop();
		dead.pop();

		int temp = adultCnt % MOD;
		result += temp;
		result %= MOD;
		baby.push(temp);
		adult.push(temp);
		dead.push(temp);
	}

	cout << result << "\n";
	return 0;
}