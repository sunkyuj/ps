#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define M 1000000007

using namespace std;

typedef long long ll;

ll m, dice[10001],sum[10001];

ll po(ll a, ll b) {
	if (b == 0) return 1;

	ll half = po(a, b / 2) % M;
	if (b % 2) return (((a % M) * half) % M * half) % M;
	else return (half * half) % M;
}


int main()
{
	FIO;
	cin >> m;
	ll E = 0;
	for (ll i = 1; i <= m; i++) {
		//cin >> dice[i] >> sum[i];
		ll Ei, Ni, Si;
		cin >> Ni >> Si; //      S/N    N is b
		Ei = (Si * (po(Ni, M - 2) % M)) % M;
		E = (E % M + Ei) % M;
	}
	cout << E;
}