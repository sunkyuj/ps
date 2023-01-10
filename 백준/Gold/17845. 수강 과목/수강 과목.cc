#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n, W; // W : 1~10000
int v[1001], w[1001];
int dp[1001][10001];

int main()
{
	FIO;
	cin >> W >> n;
	for (int i = 0; i < n; i++) cin >> v[i] >> w[i];

	for (int j = w[0]; j <= W; j++) dp[0][j] = v[0];

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= W; j++) {
			if (j - w[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n - 1][W];
}