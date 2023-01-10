#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef long long ll;
ll a, b;
int M;
ll memo[1000000] = { 1 };

//2147483647
//100000000

ll bin(ll x, ll p) {

	/*
	
	cout << p << "\n";
	for (int i = 0; i < 100000000; i++) if(memo[i]) cout << memo[i] << " ";
	cout << "\n\n";
	*/
	
	if (p < 1000000 && memo[p]) return memo[p];
	if (p >= 1000000) {
		if (p % 2) { //odd
			ll half = bin(x, p / 2);
			return (x % M * (half % M * half % M) % M) % M;

			//return memo[p] = ((x % M * bin(x, p / 2) % M) % M * bin(x, p / 2) % M) % M;
		}
		else { //even
			ll half = bin(x, p / 2);
			return (half % M * half % M) % M;

			//return memo[p] = (bin(x, p / 2) % M * bin(x, p / 2) % M) % M;
		}
	}
	
	else {
		if (p % 2) { //odd
			ll half = bin(x, p / 2);
			return memo[p] = (x % M * (half % M * half % M) % M) % M;

			//return memo[p] = ((x % M * bin(x, p / 2) % M) % M * bin(x, p / 2) % M) % M;
		}
		else { //even
			ll half = bin(x, p / 2);
			return memo[p] = (half % M * half % M) % M;

			//return memo[p] = (bin(x, p / 2) % M * bin(x, p / 2) % M) % M;
		}
	}
	
}

int main()
{
	FIO;
	cin >> a >> b >> M;

	cout << bin(a,b);
}