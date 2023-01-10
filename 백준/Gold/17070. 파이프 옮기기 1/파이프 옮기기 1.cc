#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n;
int arr[17][17];

int dy[3] = {0,1,1};
int dx[3] = {1,1,0};  //   |   0 == →   |   1 == ↘   |   2 == ↓   |
//bool visit[17][17][17][17];

bool in_range(int y, int x) {
	return y >= 0 && x >= 0 && y < n&& x < n;
}

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> arr[i][j];
	}

	queue<pair<int, int>> sq;
	queue<pair<int, int>> eq;
	sq.push({ 0,0 });
	eq.push({ 0,1 });
	//visit[0][0][0][1] = 1;

	int cnt = 0;
	while (!sq.empty()) {
		int sy = sq.front().first, sx = sq.front().second;
		int ey = eq.front().first, ex = eq.front().second;
		sq.pop(); eq.pop();

		int status=0;
		for (int i = 1; i < 3; i++) {
			int ny = sy + dy[i], nx = sx + dx[i];
			if (ny == ey && nx == ex) {
				status = i;
				break;
			}
		}

		if (ey == n - 1 && ex == n - 1) cnt++;
		else {
			if (status == 0) {//→
				for (int i = 0; i < 2; i++) {
					int ny = ey + dy[i], nx = ex + dx[i];
					if (!in_range(ny, nx)) continue;
					if (i == 1 && (arr[ny - 1][nx] || arr[ny][nx -1])) continue;
					if (arr[ny][nx]==1) continue;

					sq.push({ ey,ex });
					eq.push({ ny,nx });
					//visit[ey][ex][ny][nx] = 1;

				}
			}
			else if (status == 1) {//↘
				for (int i = 0; i < 3; i++) {
					int ny = ey + dy[i], nx = ex + dx[i];
					if (!in_range(ny, nx)) continue; 
					if (i == 1 && (arr[ny - 1][nx] || arr[ny][nx - 1])) continue;
					if (arr[ny][nx]==1) continue;

					sq.push({ ey,ex });
					eq.push({ ny,nx });
					//visit[ey][ex][ny][nx] = 1;
				}
			}
			else {//↓
				for (int i = 1; i < 3; i++) {
					int ny = ey + dy[i], nx = ex + dx[i];
					if (!in_range(ny, nx)) continue;
					if (i == 1 && (arr[ny - 1][nx] || arr[ny][nx - 1])) continue;
					if (arr[ny][nx]==1) continue;

					sq.push({ ey,ex });
					eq.push({ ny,nx });
					//visit[ey][ex][ny][nx] = 1;

				}
			}
			
		}
	}

	cout << cnt;
}