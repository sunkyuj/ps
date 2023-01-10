#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n, m;
//int arr[1025][1025];
//int memo[1025][1025];
int arr[100001];
int memo[100001];

int main()
{
	FIO;
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		memo[i+1] = sum;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << memo[b] - memo[a - 1] << "\n";

	}
	/*
	* for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			memo[i + 1][j + 1] = memo[i][j + 1] + memo[i + 1][j] + arr[i][j] - memo[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << memo[x2][y2] - memo[x2][y1 - 1] - memo[x1 - 1][y2] + memo[x1 - 1][y1 - 1] << "\n";
	}
	*/
	


}