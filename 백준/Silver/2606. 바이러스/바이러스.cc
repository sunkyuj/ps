#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n,e;
int connect[101][101];
int visited[101];
queue <int> q;

int main()
{
	FIO;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		connect[v1][v2] = connect[v2][v1] = 1;
	}
	int cnt = 0;
	q.push(1);
	visited[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (cur == i) continue;
			if (connect[cur][i] && !visited[i]) {
				q.push(i);
				visited[i] = 1;
				cnt++;
			}
		}
	}
	cout << cnt;
}