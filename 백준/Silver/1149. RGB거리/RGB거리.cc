#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
int price[1001][3]; // 0 r // 1 g // 2 b
int dp[1001][3];

int f(int level, int col) {

	if (level < 0) return 0;
	if (dp[level][col]) return dp[level][col];
	
	int r = INT_MAX, g = INT_MAX, b = INT_MAX;
	if (col != 0) r = (col == -1) ? f(level - 1, 0) : price[level][col] + f(level - 1, 0);
	if (col != 1) g = (col == -1) ? f(level - 1, 1) : price[level][col] + f(level - 1, 1);
	if (col != 2) b = (col == -1) ? f(level - 1, 2) : price[level][col] + f(level - 1, 2);

	if (col == -1) return min(r, min(g, b));
	else return dp[level][col] = min(r, min(g, b));

}

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> price[i][0] >> price[i][1] >> price[i][2];
	
	
	cout << f(n,-1);

}