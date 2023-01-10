#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n,m;
vector <pair<int, int>> v[101];
int dist[101];
bool visit[101];

void f(int start) {
	fill(dist, dist + n + 1, INT_MAX);
	

	dist[start] = 0;
	visit[start] = 1;
	priority_queue<pair<int, int>> pq;
	pq.push({0,start});//-cost,cur

	while (!pq.empty()) {
		int cost = -pq.top().first, cur = pq.top().second; // cost<=0 so -cost>0
		pq.pop();

		if (cost > dist[cur]) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i].first, ncost = v[cur][i].second;
			if (dist[nxt] > cost + ncost) {
				dist[nxt] = cost + ncost;
				pq.push({ -(cost + ncost),nxt });
			}

		}
	}
	for (int i = 1; i <= n; i++) {
		int x = (dist[i] == INT_MAX) ? 0 : dist[i];
		cout << x << " ";
	}cout << "\n";

}

int main()
{
	FIO;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
	}
	for (int i = 1; i <= n; i++) f(i);

}