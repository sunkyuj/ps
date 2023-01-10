#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cmath>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
int dp[50001];
int main()
{
	dp[1] = 1;
	FIO;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i] = 1 + dp[i - 1];
		for (int j = 2; j * j <= i; j++) dp[i] = min(dp[i], 1 + dp[i - j * j]);
	}
	cout << dp[n];

}
