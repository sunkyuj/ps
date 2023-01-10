#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
int arr[301];
int dp[301];

int f(int n) {
	if (n <= 0) return 0;
	if (dp[n]) return dp[n];

	return dp[n] = max(f(n - 2), f(n - 3) + arr[n - 1]) + arr[n];
}

int main()
{
	FIO;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cout << f(n);
}