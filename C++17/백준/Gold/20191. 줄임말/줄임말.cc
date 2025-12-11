#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string s, t;
vector<int> alphabets[26];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> s >> t;
	for (int i = 0; i < t.size(); i++) {
		int index = t[i] - 'a';
		alphabets[index].emplace_back(i);
	}

	int result = 1;
	int currentTIndex = -1;
	for (int i = 0; i < s.size(); i++) {
		int index = s[i] - 'a';
		vector<int>& alphabet = alphabets[index];
		if (alphabet.empty()) {
			result = -1;
			break;
		}
		auto it = upper_bound(alphabet.begin(), alphabet.end(), currentTIndex);
		if (it == alphabet.end()) {
			result++;
			i--;
			currentTIndex = -1;
		}
		else {
			currentTIndex = *it;
		}
	}

	cout << result << "\n";

	return 0;
}