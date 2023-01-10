#include <iostream>

using namespace std;
int A[101][101], B[101][101], C[101][101];

int main()
{
	int n, m, k;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> A[i][j];
	}

	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) cin >> B[i][j];
	}


	for (int i = 0; i < n;i++) {
		for (int j = 0; j < k; j++) {
			for (int p = 0; p < m; p++) C[i][j] += A[i][p] * B[p][j];
			cout << C[i][j] << " ";
		}
		cout << "\n";
	}

/*

n=3 m=2 k=3

1 2
3 4
5 6


-1 -2  0
 0  0  3 

 C[i][j] == A[i][0]*B[0][j] + ...+ A[i][p]*B[p][j] + ... + A[i][m]*B[m][j]
	
	
	
	*/

}
