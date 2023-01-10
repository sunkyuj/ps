#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;


int n, m;
int arr[501][501];
int memo[501][501];

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

bool in_range(int y, int x) {
	return y >= 0 && y < n&& x >= 0 && x < m;
}

int go(int py,int px, int y, int x, int len) {
	if (len == 4) return arr[y][x];

	int M = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (in_range(ny, nx)&&!(ny==py&&nx==px)) {
			int a = go(y, x, ny, nx, len + 1) + arr[y][x];
			if (a > M) M = a;
		}
	}
	return M;
}
int T(int y,int x) {
	int udlr[4];
	udlr[0] = (in_range(y - 1, x)) ? arr[y - 1][x] : 0;
	udlr[1] = (in_range(y + 1, x)) ? arr[y + 1][x] : 0;
	udlr[2] = (in_range(y, x - 1)) ? arr[y][x - 1] : 0;
	udlr[3] = (in_range(y, x + 1)) ? arr[y][x + 1] : 0;
	


	int all = arr[y][x];
	for (int i = 0; i < 4; i++) all += udlr[i];

	int M = -1;
	for (int i = 0; i < 4; i++) {
		if (all - udlr[i] > M) M = all - udlr[i];
	}

	return M;
}
/*
I,J
	4방향에 대해 go 해줌
*/


int main()
{
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> arr[i][j];
	}
	int M = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = max(go(-1, -1, i, j, 1),T(i,j));
			if (x > M) M = x;
		}
	}
	cout << M;


}

