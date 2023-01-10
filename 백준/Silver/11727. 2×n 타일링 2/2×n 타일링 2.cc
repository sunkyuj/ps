#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define M 10007
using namespace std;

int n;
int memo[1001] = {0,1,3};
int main()
{
	FIO;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		memo[i] = (memo[i - 1] % M + (memo[i - 2] * 2) % M) % M;
	}
	cout << memo[n];

}