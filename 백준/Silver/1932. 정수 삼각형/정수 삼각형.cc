#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

/*

7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

arr[i][j] -> arr[i+1][j] or arr[i+1][j+1]

*/

int n;
int arr[501][501];
int memo[501][501];

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	memo[0][0] = arr[0][0];

	for (int i = 0; i <= n-2; i++) {
		for (int j = 0; j <= i; j++) {
			if (memo[i][j] + arr[i + 1][j] > memo[i + 1][j]) 
				memo[i + 1][j] = memo[i][j] + arr[i + 1][j];
			if (memo[i][j] + arr[i + 1][j + 1] > memo[i + 1][j + 1]) 
				memo[i + 1][j + 1] = memo[i][j] + arr[i + 1][j + 1];
		}
	}
	int M = 0;
	for (int j = 0; j < n; j++) {
		if (M < memo[n - 1][j]) M = memo[n - 1][j];
	}
	cout << M;
}