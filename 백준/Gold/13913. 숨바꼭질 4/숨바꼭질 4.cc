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
vector<pair<int, int>> e[MAX];
//consider x==0

bool found = false;

void bt(int cost, int x) {

	if (x == n) {
		found = true;
		cout << x << " ";
		return;
	}

	if (!found && x - 1 >= 0 && dist[x - 1] == cost - 1) {
		bt(cost - 1, x - 1);
		if (found) {
			cout << x << " ";
			return;
		}
	}
	if (!found && x + 1 < MAX && dist[x + 1] == cost - 1) {
		bt(cost - 1, x + 1);
		if (found) {
			cout << x << " ";
			return;
		}
	}
	if (!found && x % 2 == 0 && dist[x / 2] == cost - 1) {
		bt(cost - 1, x / 2);
		if (found) {
			cout << x << " ";
			return;
		}
	}

}


int main()
{
	FIO;
	cin >> n >> k;


	//v[0].push_back({1,1});
	for (int i = 0; i <= 100000; i++) {
		if (i - 1 >= 0) e[i].push_back({ 1,i - 1 });
		if (i + 1 < MAX) e[i].push_back({ 1,i + 1 });
		if (i * 2 < MAX) e[i].push_back({ 1,i * 2 });
	}
	fill(dist, dist + MAX, MAX);

	int m = MAX, cnt = 0;
	priority_queue<pair<int, int>> pq; //{-cost,x} 중복이 안되네....
	pq.push({ 0,n });
	dist[n] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first, x = pq.top().second;
		pq.pop();
		if (x == k) {
			m = cost;
			break;
		}
		if (dist[x] < cost) continue;
		for (int i = 0; i < e[x].size(); i++) {
			int ncost = e[x][i].first, nxt = e[x][i].second;
			if (dist[nxt] > cost + ncost) {
				dist[nxt] = cost + ncost;
				pq.push({ -dist[nxt], nxt });
			}
		}
		//printPQ(pq);
	}



	cout << m << "\n";
	bt(m, k);

}