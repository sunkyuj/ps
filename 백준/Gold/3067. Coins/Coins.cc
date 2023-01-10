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
		for (int i = 0; i < n; i++) cin >> coin[i];
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
			dp[1][2] = dp[1-1][2] + dp[1][2-2(=coin[1])]
			dp[1][3] = dp[1-1][3] + dp[1][3-2]

			dp[i][j] = dp[i-1][j] + if(j-coin[i]>=0) dp[i][j-coin[i]]
			
			dp[i][j] = i번째 동전까지 써서 j원 만들 수 있는 경우의 수
			
				dp[i][j] += dp[i-1][j] <- 우선 이걸 더해줌. 이번 coin이 j원보다 클수도 있음
				
				if(j-coin[i]>=0) 
					dp[i][j] += dp[i][j-coin[i]] 

					예를들어 dp[1][4]를 구한다고 치자
					우선 dp[0][4]를 더해준다. (coin[0]으로만 4 만드는 경우의 수)
					그후 4를 만들건데 4에서 coin[1]원 어치는 미리 빼준다. 
					(coin[1]이 들어갈 자리를 미리 만든다고 생각)
					그러면 i=1 까지의 코인들로 4-coin[1] == 2 원을 만들어야하므로
					dp[i][j-coin[i]] 를 더해준다.



		*/
	}
}