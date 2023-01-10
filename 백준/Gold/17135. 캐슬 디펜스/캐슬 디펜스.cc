#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n, m, d, board[16][16], M = 0;
int dy[3] = { 0,-1,0 }, dx[3] = { -1,0,1 };

bool in_range(int y, int x) {
	return y >= 0 && x >= 0 && y < n&& x < m;
}

pair<int, int> target(int archer_y, int archer_x, bool killed[16][16]) {

	queue<pair<pair<int, int>, int>> q;
	bool visit[16][16] = {};

	q.push({ { archer_y - 1,archer_x } ,1 });
	visit[archer_y][archer_x] = 1;

	while (!q.empty()) {
		int y = q.front().first.first, x = q.front().first.second, len = q.front().second;
		q.pop();

		if (board[y][x] == 1 && !killed[y][x]) return { y,x };
		if (len == d) continue;

		for (int k = 0; k < 3; k++) {
			int ny = y + dy[k], nx = x + dx[k];
			if (in_range(ny, nx) && !visit[ny][nx]) {
				q.push({ {ny,nx},len + 1 });
				visit[ny][nx] = 1;
			}
		}
	}

	return { -1,-1 };
}

int f(int a, int b, int c) {
	int archer_y = n, cnt = 0;
	bool killed[16][16] = {};
	for (int i = 0; i < n; i++) {
		pair<int, int> a_target = target(archer_y, a, killed);
		pair<int, int> b_target = target(archer_y, b, killed);
		pair<int, int> c_target = target(archer_y, c, killed);

		if (a_target.first != -1 && !killed[a_target.first][a_target.second]) {
			killed[a_target.first][a_target.second] = 1;
			cnt++;
		}
		if (b_target.first != -1 && !killed[b_target.first][b_target.second]) {
			killed[b_target.first][b_target.second] = 1;
			cnt++;
		}
		if (c_target.first != -1 && !killed[c_target.first][c_target.second]) {
			killed[c_target.first][c_target.second] = 1;
			cnt++;
		}
		archer_y--;
	}

	return cnt;
}

int main()
{
	FIO;
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> board[i][j];
	}

	for (int a = 0; a < m; a++) {
		for (int b = a + 1; b < m; b++) {
			for (int c = b + 1; c < m; c++) {

				int x = f(a, b, c);
				if (M < x) M = x;
			}
		}
	}
	cout << M;


}