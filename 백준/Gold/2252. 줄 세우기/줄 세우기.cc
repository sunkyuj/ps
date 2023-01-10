#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n, m;

int req[32001];
vector<int> P[32001];
//vector<int> Q[32001];

int main()
{
	FIO;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		P[a].push_back(b);
		//Q[b].push_back(a);
		req[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (req[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (auto& x : P[cur]) {
			if (--req[x] == 0) {
				q.push(x);
			}
		}
	}
}