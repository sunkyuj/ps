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

int nodes[1001];
int prev_node[1001];

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
	pq.push({ 0,s });
	dist[s] = 0;
	nodes[s] = 1;
	while (!pq.empty()) {
		int cost = -pq.top().first, x = pq.top().second;
		pq.pop();

		if (dist[x] < cost) continue;
		for (int i = 0; i < edge[x].size(); i++) {
			int ncost = edge[x][i].second, nxt = edge[x][i].first;
			if (dist[nxt] > cost + ncost) {
				dist[nxt] = cost + ncost;
				prev_node[nxt] = x;
				nodes[nxt] = nodes[x] + 1;
				pq.push({ -dist[nxt],nxt });
			}
		}
	}
	cout << dist[e]<<"\n"<<nodes[e]<<"\n";
	vector<int> st;
	int x = e;
	while (x != s) {
		st.push_back(x);
		x = prev_node[x];
	}st.push_back(x);
	while (!st.empty()) {
		cout << st.back() << " ";
		st.pop_back();
	}

}