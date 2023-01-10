#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;


int memo[42];

int main()
{
	FIO;
	for (int i = 0; i < 10; i++) {
		int a;
		cin >> a;
		memo[a % 42] = 1;
	}
	int cnt = 0;
	for (int i = 0; i < 42; i++) {
		if (memo[i]) cnt++;
	}
	cout << cnt;
}