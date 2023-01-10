#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 10000000

using namespace std;

int n, m, r;
int item[101];
vector<pair<int, int>> e[101];
int dist[101];

int D(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start }); // -cost,x
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first, x = pq.top().second;
		pq.pop();

		if (dist[x] < cost) continue;

		for (int i = 0; i < e[x].size(); i++) {
			int ncost = e[x][i].second, nxt = e[x][i].first;
			if (dist[nxt] > ncost + cost&& ncost + cost<=m) {
				dist[nxt] = ncost + cost;
				pq.push({-dist[nxt],nxt});
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] > m) continue;
		sum += item[i];
	}
	return sum;

}

int main()
{
	FIO;
	cin >> n >> m >> r;
	
	for (int i = 1; i <= n; i++) cin >> item[i];
	for (int i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a].push_back({ b,c });
		e[b].push_back({ a,c });
	}


	int M = 0;
	for (int i = 1; i <= n; i++) {
		fill(dist, dist + 1 + n, MAX);
		int item_sum=D(i);
		if (M < item_sum) M = item_sum;
		
	}
	cout << M;

} 