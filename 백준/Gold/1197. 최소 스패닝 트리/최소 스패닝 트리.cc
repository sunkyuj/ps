#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n, e;
vector<pair<int, int>> edge[10001];
bool visit[10001];

int main()
{
	FIO;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });// -cost, to_node
	
	int sum = 0;
	int cnt = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first, x = pq.top().second;
		pq.pop();

		if (visit[x]) continue;

		visit[x] = 1;
		sum += cost;
		cnt++;
		

		if (cnt == n) break;

		for (int i = 0; i < edge[x].size(); i++) {
			int  to = edge[x][i].first, ncost = edge[x][i].second;
			if (!visit[to]) {
				pq.push({ -ncost,to });
				//visit[to] = 1;
			}
		}
	}

	cout << sum;
}

/*


7 11
1 7 12
1 4 28
1 2 67
2 4 24
1 5 17
2 5 62
3 5 20
3 6 37
4 7 13
5 6 45
5 7 73


*/

