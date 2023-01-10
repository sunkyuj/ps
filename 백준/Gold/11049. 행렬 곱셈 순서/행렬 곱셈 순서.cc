#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n;
int r[501], c[501];

int dp[501][501]; // dp[s][e] : s~e까지 곱할 때의 최소 계산 횟수


int main()
{
	FIO;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> r[i] >> c[i];
	//항상 순서대로 곱셈을 할 수 있는 크기만 입력으로 주어진다.

	for (int i = 0; i < n - 1; i++) dp[i][i + 1] = r[i] * c[i] * c[i + 1];

	for (int d = 2; d <= n - 1; d++) { //diff
		for (int i = 0; i + d < n; i++) {
			int j = i + d;
			for (int k = i; k < j; k++) {
				int res = dp[i][k] + dp[k + 1][j] + r[i] * c[k] * c[j];
				if (dp[i][j] == 0 || dp[i][j] > res) dp[i][j] = res;
			}
		}
	}
	cout << dp[0][n - 1];
	
}