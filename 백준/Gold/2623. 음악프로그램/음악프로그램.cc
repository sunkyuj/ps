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

int main()
{
	FIO;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;

		int a,b;
		cin >> a;
		for (int j = 1; j < k; j++) {
			cin >> b;
			P[a].push_back(b);
			req[b]++;
			a = b;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (req[i] == 0) q.push(i);
	}
	int cnt = 0;;
	vector<int> ans;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		ans.push_back(cur);
		cnt++;
		//cout << cur << "\n";
		for (auto& x : P[cur]) {
			if (--req[x] == 0) {
				q.push(x);
			}
		}
	}
	if (q.empty() && cnt != n) cout << 0;
	else for (auto& x : ans) cout << x << "\n";
	
}