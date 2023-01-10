#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n, k;
int fac(int n) {
	if (n <= 1) return 1;

	return n * fac(n - 1);

}
int main()
{
	FIO;
	cin >> n >> k;
	int down = fac(k) * fac(n - k);
	cout << fac(n) / down;

}



/*

(n,k) = n!/(k!*(n-k)!)

목 시흥
금 서울
토 세종

*/