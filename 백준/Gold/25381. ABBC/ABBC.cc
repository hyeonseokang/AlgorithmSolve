#include<iostream>
#include<string>
#include<queue>

using namespace std;

string s;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;

	int result = 0;
	for (int i = 0; i < s.size(); i++) {
		const char c = s[i];
		if (c == 'B') {
			q.push(i);
		}
		else if (c == 'C' && q.empty() == false) {
			q.pop();
			result++;
		}
	}

	for (int i = 0; i < s.size(); i++) {
		const char c = s[i];
		if (c == 'A') {
			while (!q.empty() && q.front() < i) {
				q.pop();
			}

			if (!q.empty()) {
				result++;
				q.pop();
			}
		}
	}

	cout << result << "\n";
	return 0;
}