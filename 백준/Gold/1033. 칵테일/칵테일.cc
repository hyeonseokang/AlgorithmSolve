#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector <pair<int, pair<long long, long long>>> ratio[10];
bool visited[10] = { false };
long long results[10];
long long sumLCM = 1;

long long gcd(long long a, long long b) {
	if (b == 0) return a;

	return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

void solve(int s, long long l) {
	results[s] = l;
	visited[s] = true;
	vector<pair<int, pair<long long, long long>>>& r = ratio[s];

	for (int i = 0; i < r.size(); i++) {
		int e = r[i].first;
		if (visited[e] == true) continue;
		long long a = r[i].second.first;
		long long b = r[i].second.second;

		solve(e, l / a * b);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		long long p, q;
		cin >> a >> b >> p >> q;

		sumLCM *= lcm(p, q);
		ratio[a].emplace_back(b, make_pair(p, q));
		ratio[b].emplace_back(a, make_pair(q, p));
	}

	solve(0, sumLCM);

	long long g = results[0];
	for (int i = 1; i < n; i++) {
		g = gcd(g, results[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << results[i] / g << "\n";
	}
	
	return 0;
}