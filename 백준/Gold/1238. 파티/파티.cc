#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 10000001

using namespace std;

int n, m, x;
int dist[1001][1001];

int main()
{
	FIO;
	cin >> n >> m >> x;
	fill(&dist[0][0], &dist[n][n], MAX);

	for (int i = 1; i <= m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		dist[from][to] = cost;
	}
	for (int i = 1; i <= n; i++) dist[i][i] = 0;

	for (int k = 1; k <= n; k++) {
		//i = 출발노드
		for (int i = 1; i <= n; i++) {
			if (dist[i][k] == MAX) continue;
			//j = 도착노드
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int M = 0;
	for (int i = 1; i <= n; i++) {
		if (M < dist[i][x] + dist[x][i]) M = dist[i][x] + dist[x][i];
	}
	cout << M;
}
/*

3 4 2
1 2 1
2 1 4
3 2 3
2 3 4
*/