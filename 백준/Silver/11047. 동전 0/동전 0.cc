#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n, k;
int coin[11];


int f(int goal) {
	int cnt = 0;
	for (int i = n - 1; i >= 0&&goal; i--) {
		if (coin[i] <= goal) {
			cnt += goal / coin[i];
			goal %= coin[i];
		}
	}
	return cnt;
}

int main()
{
	FIO;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> coin[i];

	cout << f(k);
}