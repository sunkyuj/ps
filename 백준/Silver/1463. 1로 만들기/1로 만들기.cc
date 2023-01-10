#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
//10^6==1,000,000
int n;

int min_cnt = INT_MAX;

int memo[1000001] = {0,0,1,1};

int f(int n) {
	if (memo[n]!= INT_MAX) {
		return memo[n];
	}
	
	if (n % 3 == 0) {
		memo[n] = min(memo[n],min(memo[n / 3]+1, f(n / 3)+1)) ;
		
	}
	if (n % 2 == 0) {
		memo[n] = min(memo[n], min(memo[n / 2]+1, f(n / 2)+1));
		
	}
	memo[n] = min(memo[n], min(memo[n - 1]+1, f(n - 1)+1)) ;
	
	
	return memo[n];
	
}

int main()
{
	FIO;
	
	cin >> n;

	for (int i = 4; i <= n; i++) memo[i] = INT_MAX;
	
	for (int i = 4; i <= n; i++) {
		f(i);
	}
	
	cout <<memo[n];
}