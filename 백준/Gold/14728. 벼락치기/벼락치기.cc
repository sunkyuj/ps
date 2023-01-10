#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n, t;
int study[101];
int score[101];
int dp[101][10001]; // dp[i][j] = i번째거에서 j만큼 공부해서 얻을수 있는 최대 점수

int main()
{
	FIO;
	cin >> n >> t;
	for (int i = 0; i < n; i++) cin >> study[i] >> score[i];

	
	for (int j = 0; j <= t; j++) { //dp[0][j]
		if (j - study[0] >= 0) dp[0][j] = score[0];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= t; j++) {
			if (j - study[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - study[i]] + score[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n - 1][t];
}