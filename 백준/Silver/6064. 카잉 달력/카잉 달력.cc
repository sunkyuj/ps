#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;



typedef long long ll;
ll m, n, x, y;


ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
ll lcm(ll a,ll b) {
	return a * b / gcd(a, b);
}

ll f(ll LCM) { //lcm is the cycle
	/*
	x+mk     3+10k
	y+nk'    9+12l
	*/
	vector <ll> v;
	
	for (ll i = 0; i <= LCM / m; i++) v.push_back(x + m * i);
	

	for (ll i = 0; i <= LCM / m; i++) {
		int r = v[i] % n ? v[i] % n : n;
		if (r==y) return v[i];
	}

	return -1;
}

int main()
{
	FIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> m >> n >> x >> y;
	
		cout<<f(lcm(m,n))<<"\n";
		
	}

}
/*
m=10   n=12

<x:y> 의 다음 해 <x':y'>에 대하여...

if(x<m) x'=x+1
else x'=1

if(y<n) y'=y+1
else y'=1

m=10   n=12  last year == 10:12

1 1:1
2 2:2
3 3:3
...
9 9:9
10 10:10
11 1:11
12 2:12
13 3:1

ll f(ll LCM) { //lcm is the cycle

	ll xp = 1, yp = 1;

	for (ll i = 1; i <= LCM; i++) { // i%m==x && i%n==y 인 i를 찾아라...
		if (xp == x && yp == y) return i;

		cout << i << " == <" << xp << ":" << yp << ">\n";

		if (xp < m) xp++;
		else xp = 1;
		if (yp < n) yp++;
		else yp = 1;



	}
	return -1;
}

*/