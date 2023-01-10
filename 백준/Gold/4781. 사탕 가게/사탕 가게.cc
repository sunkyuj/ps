#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n,m,c[5001],p[5001]; //<-val,price(쓸때는 j/100 해주고, 넣을때는 j*100 에다가 넣는다)
//int dp[5001][10001]; // 쓸때는 j/100 해주고, 넣을때는 j*100 에다가 넣는다.
int dp[10001];

double _m, tmp;//<-weight

int main()
{
	FIO;
	while (1) {
		
		cin >> n >> _m; // 이 문제는 한 사탕을 여러개 넣을 수 있다.
		m = (int)(_m * 100 + 0.5); //부동소수점 오차때문에 해준다.

		if (n == 0 && m == 0.00) break;

		for (int i = 0; i < n; i++) {
			cin >> c[i] >> tmp;
			p[i] = (int)(tmp * 100 + 0.5); //부동소수점 오차때문에 해준다.
		}

		/*
		int first_price = p[0];
		dp[0][first_price] = c[0];
		for (int j = first_price + 1; j <= m; j++) {
			dp[0][j] = dp[0][j - 1];
			if (j % first_price == 0) dp[0][j] += c[0];
		}
		*/

		for (int i = 0; i < n; i++) {
			for (int j = p[i]; j <= m; j++) {
				dp[j] = max(dp[j], dp[j - p[i]] + c[i]);
			}
		}
		cout << dp[m] << "\n";

		/*
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= m; j++) {


				
				if (j - p[i] >= 0) {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - p[i]] + c[i]);
				}
				else dp[i][j] = dp[i - 1][j];
			}
		}
		
		cout << dp[n - 1][m]<<"\n";*/
		memset(dp,0,sizeof(dp));
	}
}

//dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price] + c[i]);
//dp[i][j] = max(dp[i][j], dp[i][j - price] + c[i]);