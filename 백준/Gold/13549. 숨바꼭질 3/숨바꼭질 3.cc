#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 100001

using namespace std;

int n, k;
int dist[MAX];
vector<pair<int,int>> e[MAX];
//consider x==0


int main()
{
	FIO;
	cin >> n >> k;
	if (n > k) {
		cout << n - k;
		return 0;
	}
	
	//v[0].push_back({1,1});
	for (int i = 0; i <= 100000; i++) {
		if (i - 1 >= 0) e[i].push_back({ 1,i-1 });
		if (i + 1 < MAX) e[i].push_back({ 1,i+1 });
		if (i * 2 < MAX) e[i].push_back({ 0,i*2 });
	}
	fill(dist, dist + MAX, MAX);

	priority_queue<pair<int, int>> pq; //{-cost,x}
	pq.push({ 0,n });
	dist[n] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first, x = pq.top().second;
		pq.pop();
		if (x == k) {
			cout << cost;
			return 0;
		}
		if (dist[x] < cost) continue;
		for (int i = 0; i < e[x].size(); i++) {
			int ncost = e[x][i].first, nxt = e[x][i].second;
			if (dist[nxt] > cost + ncost) {
				dist[nxt] = cost + ncost;
				pq.push({ -dist[nxt], nxt });
			}
		}
		
	}

	//cout << f(n);

}