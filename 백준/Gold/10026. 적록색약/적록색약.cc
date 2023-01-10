#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
string color[101];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };


int normal() {
	queue<pair<int, int>> q;
	bool visited[101][101] = {0};
	int cnt=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				q.push({ i,j });
				visited[i][j] = 1;
				char c = color[i][j];
				cnt++;
				while (!q.empty()) {
					int y = q.front().first, x = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int ny = y + dy[i], nx = x + dx[i];
						if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx] && color[ny][nx] == c) {
							q.push({ ny,nx });
							visited[ny][nx] = 1;
						}
					}
				}
			}
		}
	}
	return cnt;
}
int disable() {
	queue<pair<int, int>> q;
	bool visited[101][101] = { 0 };
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				q.push({ i,j });
				visited[i][j] = 1;
				bool is_b = color[i][j] == 'B' ? true : false;
				cnt++;
				while (!q.empty()) {
					int y = q.front().first, x = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int ny = y + dy[i], nx = x + dx[i];
						if (is_b) {
							if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx] && color[ny][nx]=='B') {
								q.push({ ny,nx });
								visited[ny][nx] = 1;
							}
						}
						else {
							if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx] && color[ny][nx] != 'B') {
								q.push({ ny,nx });
								visited[ny][nx] = 1;
							}
						}
						
					}
				}
			}
		}
	}
	return cnt;;
}

int main()
{
	FIO;
	// if disable --> r==g
	cin >> n;
	for (int i = 0; i < n; i++) cin >> color[i];
	cout << normal() <<" "<< disable();

}