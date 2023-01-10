#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n, m;
int arr[9][9];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

bool in_range(int y, int x) {
	return y >= 0 && y < n&& x >= 0 && x < m;
}

int bfs() {
	bool visit[9][9] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 2) {
				queue<pair<int, int>> q;
				q.push({ i,j });
				visit[i][j] = 1;
				while (!q.empty()) {
					int y = q.front().first, x = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k], nx = x + dx[k];
						if (in_range(ny, nx)&&arr[ny][nx]==0&&!visit[ny][nx]) {
							q.push({ ny,nx });
							visit[ny][nx] = 1;
						}
					}
				}
			}
		}
	}
	/*
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\nvisit\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}*/
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && arr[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

int main()
{
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> arr[i][j];
	}


	int M = 0;
	for (int i1 = 0; i1 < n; i1++) {
		for (int j1 = 0; j1 < m; j1++) {
			if (!in_range(i1, j1) || arr[i1][j1] != 0) continue;
			arr[i1][j1] = 3;

			for (int i2 = 0; i2 < n; i2++) {
				for (int j2 = 0; j2 < m; j2++) {
					if (!in_range(i2, j2) || arr[i2][j2] != 0) continue;
					arr[i2][j2] = 3;

					for (int i3 = 0; i3 < n; i3++) {
						for (int j3 = 0; j3 < m; j3++) {
							if (!in_range(i3, j3) || arr[i3][j3] != 0) continue;
							arr[i3][j3] = 3;

							int c=bfs();
							if (M < c) M = c;

							arr[i3][j3] = 0;
						}
					}
					arr[i2][j2] = 0;
				}
			}
			arr[i1][j1] = 0;
		}
	}
	cout << M;
}