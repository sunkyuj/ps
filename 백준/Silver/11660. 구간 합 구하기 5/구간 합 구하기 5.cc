#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n, m;
int arr[1025][1025];
int memo[1025][1025];

int main()
{
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			/*if (i == 0) memo[i][j] = arr[i][j];
			else if (j == 0) memo[i][j] = memo[i - 1][j] + arr[i][j];
			else*/ 
			memo[i + 1][j + 1] = memo[i][j + 1] + memo[i + 1][j] + arr[i][j] - memo[i][j];
		}
	}
	

	/*
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cout << memo[i][j] << " ";
		cout << "\n";
	}cout << "\n";
	*/

	for (int i = 0; i < m; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		//cout << " memo[y2][x2] : " << memo[y2][x2] << ", memo[y2][x1-1] : " << memo[y2][x1 - 1] << ", memo[y1-1][x2] : " << memo[y1 - 1][x2] << ", memo[y1-1][x1-1]"<< memo[y1 - 1][x1 - 1] <<"\n";
		cout << memo[x2][y2] - memo[x2][y1-1] - memo[x1-1][y2] + memo[x1-1][y1-1]<<"\n";
	}


}