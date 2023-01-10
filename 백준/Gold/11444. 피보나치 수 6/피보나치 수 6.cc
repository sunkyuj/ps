#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 1000000000000000000 //백경, 롱롱(9백경)보다 작긴함
#define M 1000000007

using namespace std;
typedef long long ll;
typedef struct matrix {
	ll ul; ll ur;
	ll dl; ll dr;
}matrix;

ll n;

ll make_cycle(ll mod) {
	ll a = 0, b = 1, tmp;
	for (ll i = 1; i < mod * mod; i++) {
		tmp = (b + a) % mod;
		a = b;
		b = tmp;
		if (a == 0 && b == 1) return i;
	}
}
matrix mul(matrix A, matrix B) {
	matrix C;
	C.ul = ((A.ul * B.ul) % M + (A.ur * B.dl) % M) % M;
	C.ur = ((A.ul * B.ur) % M + (A.ur * B.dr) % M) % M;
	C.dl = ((A.dl * B.ul) % M + (A.dr * B.dl) % M) % M;
	C.dr = ((A.dl * B.ur) % M + (A.dr * B.dr) % M) % M;
	return C;
}
matrix set_left() {
	matrix A;
	A.ul = 1;
	A.ur = 1;
	A.dl = 1;
	A.dr = 0;
	return A;
}
matrix set_right() {
	matrix A;
	A.ul = 1;
	A.ur = 0;
	A.dl = 0;
	A.dr = 0;
	return A;
}

matrix pow(matrix A, ll i) {
	if (i == 1) {
		return A;
	}

	matrix half = pow(A, i / 2);
	if (i % 2) {
		return mul(mul(half,half),A);
	}
	else {
		return mul(half, half);
	}
}

int main()
{
	FIO;
	cin >> n;
	matrix A = set_left();
	matrix A_pow = pow(A, n);
	cout << A_pow.dl;
	 
}