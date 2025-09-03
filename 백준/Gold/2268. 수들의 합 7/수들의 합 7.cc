#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<long long> segments;
vector<int> numbers;

void Init(int i, int l, int r)
{
	if (l == r) {
		segments[i] = numbers[l];
		return;
	}

	int child = i * 2;
	int m = (l + r) / 2;
	Init(child, l, m);
	Init(child + 1, m + 1, r);
	
	segments[i] = segments[child] + segments[child + 1];
}

void Modify(int i, int l, int r, int key, int value) {
	if (l == r) {
		segments[i] = value;
		return;
	}
	int child = i * 2;
	int m = (l + r) / 2;

	if (key <= m) {
		Modify(child, l, m, key, value);
	}
	else {
		Modify(child + 1, m + 1, r, key, value);
	}

	segments[i] = segments[child] + segments[child + 1];
}

long long Sum(int i, int l, int r, int cl, int cr) {
	if (cl == l && cr == r) {
		return segments[i];
	}
	int child = i * 2;
	int m = (l + r) / 2;
	
	long long result = 0;
	if (cl <= m) {
		result += Sum(child, l, m, cl, min(cr, m));
	}
	if (cr > m) {
		result += Sum(child + 1, m + 1, r, max(cl, m + 1), cr);
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	segments.resize(4 * (n + 1));
	numbers.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int oper, a, b;
		cin >> oper >> a >> b;

		if (oper == 0) {
			if (a > b) swap(a, b);
			cout << Sum(1, 1, n, a, b) << "\n";
		}
		else if (oper == 1) {
			Modify(1, 1, n, a, b);
		}
	}

	return 0;
}