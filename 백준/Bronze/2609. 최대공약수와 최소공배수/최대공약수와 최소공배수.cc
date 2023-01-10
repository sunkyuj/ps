#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef long long ll;

ll GCD(ll a, ll b) {
	ll tmp;
	while (a) {
		tmp = b % a;
		b = a;
		a = tmp;
	}
	return b;
}

int main()
{
	FIO;
	ll a, b;
	cin >> a >> b;
	if (a > b) swap(a, b); //a<b

	ll gcd = GCD(a,b);
	cout << gcd << "\n" << a * b / gcd;

}