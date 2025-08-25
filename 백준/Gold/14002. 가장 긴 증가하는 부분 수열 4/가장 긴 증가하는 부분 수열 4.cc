#include <iostream>
#include <stack>
using namespace std;

int numbers[1000];
int dp[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Max = 0;

	int idx = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> numbers[i];

		for (int j = 0; j < i; ++j)
		{
			if (numbers[j] < numbers[i]
				&& dp[j] > dp[i])
			{
				dp[i] = dp[j];
			}
		}

		dp[i] += 1;
		if (dp[i] > Max)
		{
			idx = i;
			Max = dp[i];
		}
	}

    stack<int> lis;
	lis.push(numbers[idx]);

	int j = idx;
	for (int i = idx - 1; i >= 0; --i)
	{
		if (dp[i] == dp[j] - 1)
		{
			lis.emplace(numbers[i]);
			j = i;
		}
	}

	cout << Max << '\n';
	while (!lis.empty())
	{
		cout << lis.top() << ' ';
		lis.pop();
	}
}