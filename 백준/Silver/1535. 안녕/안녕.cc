#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n;
int L[21], J[21];
int dp[21][101];

int f(int idx, int sum) {
	if (dp[idx][sum]) return dp[idx][sum];
	if (idx == n) return 0;

	int n1 = 0, n2 = 0;

	if (L[idx] + sum < 100) n1 = f(idx + 1, L[idx] + sum) + J[idx];
	n2 = f(idx + 1, sum);

	return dp[idx][sum] = max(n1, n2);
}


int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> L[i];
	for (int i = 0; i < n; i++) cin >> J[i];

	cout << f(0, 0);

}