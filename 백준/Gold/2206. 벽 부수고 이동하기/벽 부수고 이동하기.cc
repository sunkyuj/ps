#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n, m;
string arr[1001];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
//int dist[1001][1001];
bool visit0[1001][1001];
bool visit1[1001][1001];

bool visit[1001][1001][2];

queue<pair<int, int>> q;
queue<pair<int, int>> lc_q;

bool in_range(int ny, int nx) {
	return ny >= 0 && ny < n&& nx >= 0 && nx < m;
}

int main()
{
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	q.push({0,0});
	lc_q.push({1,0});
	
	visit[0][0][0] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		int len = lc_q.front().first;
		int crash = lc_q.front().second;
		q.pop(); lc_q.pop();
		if (y == n - 1 && x == m - 1) {
			cout << len;
			return 0;
		}

		//if (visit0[y][x] == 1) continue;
		//if (visit1[y][x] == 1 && crash == 1) continue;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (in_range(ny, nx) && (arr[ny][nx] - '0') * crash != 1 && !visit[ny][nx][crash] && !visit[ny][nx][0]) {
				q.push({ ny,nx });
				lc_q.push({ len + 1, arr[ny][nx] - '0' + crash });
				visit[ny][nx][arr[ny][nx] - '0'+crash] = 1;
			}
		}
	}

	cout << -1;

}

/*

8 8

01000100
01010100
01010100
01010100
01010100
01010100
01010100
00010100

*/