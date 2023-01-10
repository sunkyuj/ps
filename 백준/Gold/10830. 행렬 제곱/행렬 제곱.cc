#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector <vector<ll>> matrix;

ll n, b;
const int MOD = 1000;

matrix operator *(matrix a, matrix b) {
	matrix result(n, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				result[i][j] += a[i][k] * b[k][j];
			}
			result[i][j] %= MOD;
		}
	}
	return result;
}

matrix POW(matrix m, ll b) {

	matrix result(n,vector<ll>(n));
	for (int i = 0; i < n; i++) result[i][i] = 1;


	while(b > 0) {
		if (b % 2) { //odd
			result = result * m;
		}
		b /= 2;
		m = m * m;
	}
	
	return result;

}

int main()
{
	cin >> n >> b;
	matrix m(n,vector<ll> (n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
			if (m[i][j] >= 1000) m[i][j] %= MOD;
		}
	}

	m=POW(m, b);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}


}

