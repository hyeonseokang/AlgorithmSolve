#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include<string>

using namespace std;

long double x, y, d, t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> x >> y >> d >> t;
	long double dist = sqrt((x * x) + (y * y));
	long double result = dist;

	if (d < t) {
		cout << fixed << setprecision(20) << dist << "\n";
		return 0;
	}

	int jumpCount = dist / d;
	dist -= (jumpCount * d);
	if (jumpCount == 0) {
		result = min(result, t + d - dist);
		result = min(result, (long double)2.0 * t);
	}
	else {
		result = min(result, (long double)jumpCount * t + dist);
		result = min(result, (long double)(jumpCount + 1) * t);
	}
	cout << fixed << setprecision(20) << result << "\n";
	return 0;
}