#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n, m;
int arr[101][101];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

bool all0() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) return 0;
		}
	}
	return 1;
}

void out() {
	int visit[101][101] = {};
	queue<pair<int, int>> q;
	priority_queue<pair<int, int>> melt;
	

	q.push({ 0,0 });
	visit[0][0] = 1;
	while (!q.empty()) {
		int y = q.front().first, x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] == 0 && !visit[ny][nx]) {
				q.push({ ny,nx });
				visit[ny][nx] = 1;
			}
			else if (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] == 1) {
				visit[ny][nx]++;
				if (visit[ny][nx] >= 2) {
					melt.push({ny,nx});
				}
			}
		}
	}

	while (!melt.empty()) {
		int y = melt.top().first, x = melt.top().second;
		melt.pop();
		arr[y][x] = 0;
	}

}

int main()
{
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int t = 0;
	while (!all0()) {
		out();
		t++;
	}
	
	cout << t;

}