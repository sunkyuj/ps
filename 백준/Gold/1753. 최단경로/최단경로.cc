#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <queue>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int v, e;
int start;
//int arr[20001][20001];
vector<vector<pair<int,int>>> arr(20001);
int dist[20001];
bool visit[20001];

int main()
{
	FIO;
	cin >> v >> e >> start;
	for (int i = 1; i <= v; i++) dist[i] = INT_MAX;

	for (int i = 1; i <= e; i++) {
		int from, to, w;
		cin >> from >> to >> w;
		arr[from].push_back({w,to}); //cost node
		//arr[from][to] = w;
	}

	priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq; //cost node
	pq.push({ 0,start });
	dist[start] = 0;
	visit[start] = 1;
	while (!pq.empty()) {
		int cost = pq.top().first, cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < arr[cur].size(); i++) {
			int ncost = arr[cur][i].first, nv = arr[cur][i].second;
			if (dist[nv] > dist[cur] + ncost) {
				dist[nv] = dist[cur] + ncost;
				pq.push({ dist[nv],nv });
			}
		}
	}
	
	/*
	int cur = start;
	dist[start] = 0;
	visit[start] = 1;
	 
	while (1) {
		int m = INT_MAX;
		int mi = 0;
		for (int i = 1; i <= v; i++) {
			if (i == cur) continue;
			if (arr[cur][i]) {
				if (dist[i] > dist[cur] + arr[cur][i]) dist[i] = dist[cur] + arr[cur][i];
				if (m > dist[i]) {
					m = dist[i];
					mi = i;
				}
			}
		}
		if (mi == 0) break;
		cur = mi;
		visit[mi] = 1;
	}*/
	

	
	for (int i = 1; i <= v; i++) {
		

		if (dist[i]!=INT_MAX) cout << dist[i] << "\n";
		else cout << "INF\n";
	}
}