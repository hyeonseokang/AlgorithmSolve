#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string s, t;
vector<int> alphabets[26];
int alphabetIndex[26] = { 0 };
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
		if (alphabetIndex[index] < alphabet.size()) {
			if (currentTIndex < alphabet[alphabetIndex[index]]) {
				currentTIndex = alphabet[alphabetIndex[index]];
				alphabetIndex[index]++;
				continue;
			}
			else {
				result++;
				i--;
				currentTIndex = -1;
				memset(alphabetIndex, 0, sizeof(alphabetIndex));
			}
		}
		else {
			result++;
			i--;
			currentTIndex = -1;
			memset(alphabetIndex, 0, sizeof(alphabetIndex));
		}
	}

	cout << result << "\n";

	return 0;
}