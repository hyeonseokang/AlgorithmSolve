#include<iostream>
#include<string>
using namespace std;

long long a;
string bit;

void MinEqualsBit(const string& s, string& outString) {
	outString = "";
	bool isZeroMeet = false;
	int oneMeetCnt = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		char c = s[i];
		if (isZeroMeet == false) {
			if (c == '0') {
				isZeroMeet = true;
			}
			else {
				oneMeetCnt++;
			}
		}
		else if (c == '1') {
			outString = s.substr(0, i) + "01";
			outString = outString + string(oneMeetCnt, '1');
			outString += string(s.size() - outString.size(), '0');
			break;
		}
	}

	if (isZeroMeet == false) {
		outString = "0";
	}
}

void MaxEqualsBit(const string& s, string& outString) {
	bool isOneMeet = false;
	outString = "";
	int zeroMeetCnt = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		char c = s[i];
		if (c == '0') {
			zeroMeetCnt++;
		}

		if (c == '1') {
			isOneMeet = true;
		}
		else if (isOneMeet) {
			outString = s.substr(0, i) + "10";
			outString = outString + string(zeroMeetCnt-1, '0');
			outString += string(s.size() - outString.size(), '1');
			return;
		}
	}

	outString = "10" + string(zeroMeetCnt, '0') +
		string(s.size() - zeroMeetCnt - 1, '1');
}

void PrintBit(const string& s) {
	long long result = 0;

	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			long long temp = (1LL << (s.size() - i - 1));
			result += temp;
		}
	}

	cout << result << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> a;
	bit = "";
	long long temp = a;
	while (temp != 0) {
		char c = '0' + (temp % 2);
		bit = c + bit;
		temp /= 2;
	}

	string minResult;
	string maxResult;
	MinEqualsBit(bit, minResult);
	MaxEqualsBit(bit, maxResult);

	//cout << bit << "\n" << minResult << "\n" << maxResult << "\n";
	PrintBit(minResult);
	PrintBit(maxResult);
	cout << "\n";

	return 0;
}