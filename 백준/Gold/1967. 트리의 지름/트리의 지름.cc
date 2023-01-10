#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n;

vector<pair<int,int>> v[10001]; // v[from] = { to , cost }
bool visit[10001];

pair<int,int> bfs(int start) { //node,len
	memset(visit, 0, sizeof(visit));
	
	queue<pair<int, int>> q;
	int M_node = 0;
	int M = 0;

	q.push({ start,0 });
	visit[start] = 1;

	while (!q.empty()) {
		int cur = q.front().first, len = q.front().second;
		q.pop();
		if (M < len) {
			M_node = cur;
			M = len;
		}

		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i].first, cost = v[cur][i].second;
			if (!visit[nxt]) {
				q.push({ nxt,cost + len });
				visit[nxt] = 1;
			}
		}
	}
	return { M_node,M };
	
}

int main()
{
	FIO;
	cin >> n;
	for (int i = 1; i <= n-1; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
		v[to].push_back({ from,cost });
	}

	cout << bfs(bfs(1).first).second;

}