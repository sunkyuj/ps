#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
int arr[3][100001];
int dp[3][100001];


int main()
{
	FIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) cin >> arr[i][j];
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[2][0] = 0;

		for (int i = 1; i < n; i++) {
			dp[0][i] = arr[0][i] + max(dp[1][i - 1], dp[2][i - 1]);
			dp[1][i] = arr[1][i] + max(dp[0][i - 1], dp[2][i - 1]);
			dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]);
		}


		cout << max(dp[0][n - 1], max(dp[1][n - 1], dp[2][n - 1])) << "\n";

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < n; j++) dp[i][j] = 0;
		}
	}

}