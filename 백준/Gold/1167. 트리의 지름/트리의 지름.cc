#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <queue>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 100001



using namespace std;

int n;
vector<vector<pair<int, int>>> v(MAX);

int visited[MAX];

pair<int, int> bfs(int start) {
	queue<pair<int, int>> q;
	q.push({ start,0 });
	visited[start] = 1;

	int deepest_v = 0, deepest_len = 0;
	while (!q.empty()) {
		int cur = q.front().first, len = q.front().second;
		q.pop();
		if (deepest_len < len) {
			deepest_len = len;
			deepest_v = cur;
		}
		for (int j = 0; j < v[cur].size(); j++) {
			pair<int, int> p = v[cur][j];
			if (!visited[p.first]) {
				q.push({ p.first,p.second + len });
				visited[p.first] = 1;
			}
		}
	}

	return { deepest_v,deepest_len };
}

int main()
{
	FIO;
	//vector<pair<int, int>> x;
	//v.push_back(x);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int from, to, len;
		//vector<pair<int, int>> pairs;
		cin >> from;
		while (1) {
			cin >> to;
			if (to == -1) break;
			cin >> len;
			v[from].push_back({to,len});
		}
		//v.push_back(pairs);
	}//input


	pair<int,int> deepest=bfs(1);

	for (int k = 1; k <= n; k++) visited[k] = 0;

	cout << bfs(deepest.first).second;
}

