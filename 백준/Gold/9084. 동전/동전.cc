#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n,m;
int coin[21];
//int coin[10001];
int memo[10001]; // memo[m] = m원 만들때 경우의수
//int dp[10001];
/*
int f(int m) {
	if (dp[m]) return dp[m];

	if (m == 0) {
		return 1;
	}

	for (int i = n-1; i >= 0; i--) {
		if (m - clist[i] >= 0) dp[m] += f(m - clist[i]);
	}

	return dp[m];
}
*/

int dp[21][10001];
int main()
{
	FIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> coin[i];
			//coin[clist[i]] = 1;
		}
		cin >> m;

		dp[0][0] = 1;
		for (int j = 1; j <= m; j++) { // coin[0]
			if (j % coin[0] == 0) dp[0][j] = 1;
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= m; j++) { 
				dp[i][j] += dp[i - 1][j];
				if (j - coin[i] >= 0) {
					dp[i][j] += dp[i][j - coin[i]];
				}
			}
		}
		cout << dp[n - 1][m]<<"\n";
		memset(dp, 0, sizeof(dp));

		/*
			
			dp[0][1] = 1
			dp[0][10000] = 1

			dp[1][1] = dp[1-1][1]
			dp[1][2] = dp[1-1][2] + dp[1][2-2]


		*/


		//cout << f(m);

		/*
		memo[0] = 1;
		for (int i = 1; i <= m; i++) {
			for (int c = 0; c < n; c++) {
				if (i - clist[c] >= 0) 
					memo[i] += memo[i - clist[c]];
			}
		}
		cout << memo[m] << "\n";
		*/
	}
}