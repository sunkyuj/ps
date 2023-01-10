#include <iostream>
#include <limits.h>

using namespace std;

typedef long long ll;

ll a, b;


ll gcd(ll a, ll  b) {

	int tmp;

	while (a) {
		tmp = b % a;
		b = a;
		a = tmp;
	
	}
	return b;

}
/*

a:최대공약수
b:최소공배수


x,y
x/a 와 y/a 는 서로소

b = x * y / a


a <= x,y <=b

a <= x,ab/x <=b

ab == xy

y== ab/x


a=6, b=180

ab = 1080

 x    y
12   90
30   36
18   60
 6  180

*/

int main()
{
	ll min_ans = INT_MAX;
	ll x=0, y=0;
	cin >> a >> b;
	ll ab = a * b;


	for (ll i = 1;i*i<=ab; i++) {
		int j=0;
		if (ab % i == 0 && ab/i<=b && (ab/i)%a==0 && i%a==0) j = ab / i;
		else continue;
		
		if (gcd(i, j) != a) continue;

		if (j != 0&&min_ans>i+j) {
			x = i;
			y = j;
		}
	}
	cout << x << " " << y;
	


}
