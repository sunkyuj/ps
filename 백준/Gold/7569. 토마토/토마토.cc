#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <tuple>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;



int m, n, h; //m가 n세 h높
int box[101][101][101];//[h][n][m]
int visited[101][101][101];
//int danji[101][101][101];

int dz[6] = { 1,0,0,-1,0,0 };
int dy[6] = { 0,1,0,0,-1,0 };
int dx[6] = { 0,0,1,0,0,-1 };

queue<tuple<int,int,int>> q;

int in_range(int z, int y, int x) {
	return (z >= 0 && z < h) && (y >= 0 && y < n) && (x >= 0 && x < m);
}
int all_good() {
	for (int z = 0; z < h; z++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (box[z][y][x] == 0) {
					return 0;
				}
			}
		}
	}
	return 1;
}

int main()
{
	FIO;
	cin >> m >> n >> h;
	for (int z = 0; z < h; z++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				cin >> box[z][y][x];
				if (box[z][y][x] == 1) {
					q.push({ z,y,x });
					visited[z][y][x] = 1;
				}
			}
		}
	}
	int day = 0;
	while (!all_good()) {
		queue<tuple<int, int, int>> new_q;
		while (!q.empty()) {
			int  z = get<0>(q.front()), y = get<1>(q.front()), x = get<2>(q.front());
			q.pop();
			
			for (int i = 0; i < 6; i++) {
				int nz = z + dz[i], ny = y + dy[i], nx = x + dx[i];
				if (in_range(nz, ny, nx) && !visited[nz][ny][nx] && box[nz][ny][nx] == 0) {
					new_q.push({ nz,ny,nx });
					visited[nz][ny][nx] = 1;
				}
			}
		}

		if (!all_good() && new_q.empty()) {
			cout << -1;
			return 0;
		}
		while (!new_q.empty()) {
			int  z = get<0>(new_q.front()), y = get<1>(new_q.front()), x = get<2>(new_q.front());
			box[z][y][x] = 1;
			q.push(new_q.front());
			new_q.pop();
		}

		day++;
	}
	cout << day;
}