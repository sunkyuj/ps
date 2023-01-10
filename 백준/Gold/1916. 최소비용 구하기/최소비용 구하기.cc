#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 1000000000

using namespace std;

vector<pair<int, int>> edge[1001];

int n, m;
int s, e;
int dist[1001];

int main()
{
	FIO;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edge[from].push_back({ to,cost });
	}
	fill(dist, dist + n + 1, MAX);
	
	cin >> s >> e;
	priority_queue<pair<int, int>> pq; //-cost,x
	pq.push({0,s});
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
	cout << dist[e];

}