#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 200000001

using namespace std;

int n, e;
vector<pair<int, int>> edge[200001];
int must1, must2;
int ds[801];
int dm1[801];
int dm2[801];
//int go_must[801][2];

void Dij(int dist[], int start) {
	priority_queue<pair<int, int>> pq; // -cost, node
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cost = -pq.top().first, x = pq.top().second;
		pq.pop();

		if (dist[x] < cost) continue;

		for (int i = 0; i < edge[x].size(); i++) {
			int ncost = edge[x][i].second, nxt = edge[x][i].first;
			if (dist[nxt] > cost + ncost) {
				dist[nxt] = cost + ncost;
				pq.push({ -dist[nxt],nxt });
			}
		}
	}
}

int main()
{
	FIO;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edge[from].push_back({ to,cost });
		edge[to].push_back({ from,cost });
	}
	cin >> must1 >> must2;
	fill(ds, ds + n + 1, MAX);
	fill(dm1, dm1 + n + 1, MAX);
	fill(dm2, dm2 + n + 1, MAX);

	Dij(ds, 1);
	Dij(dm1, must1);
	Dij(dm2, must2);
	ds[1] = 0, dm1[must1] = 0, dm2[must2] = 0;

	int m1_first = ds[must1] + dm1[must2] + dm2[n], m2_first = ds[must2] + dm2[must1] + dm1[n];
	int m = min(m1_first, m2_first);
	if (m >= MAX) cout << -1;
	else cout << m;


	/*
	for (int i = 1; i <= n; i++) cout << ds[i] << " ";
	cout << "\n";
	for (int i = 1; i <= n; i++) cout << dm1[i] << " ";
	cout << "\n";
	for (int i = 1; i <= n; i++) cout << dm2[i] << " ";
	cout << "\n";
	*/

}