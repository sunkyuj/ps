#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int connected[101][101];
int n, m;
int kb[101];

int make_kb(int k) {
	int visited[101] = {};
	queue<int> q;
	queue<int> new_q;
	q.push(k);
	visited[k] = 1;

	int sum = 0;
	int level = 0;
	while (1) {
		level++;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
		
			for (int i = 1; i <= n; i++) {
				if (connected[cur][i] && !visited[i]) {
					new_q.push(i);
					visited[i] = 1;
				}
			}
		}
		if (new_q.empty()) return sum;
		
		sum += new_q.size() * level;
		while (!new_q.empty()) {
			q.push(new_q.front());
			new_q.pop();
		}
	}
}

int main()
{
	FIO;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		connected[a][b] = connected[b][a] = 1;
	}
	int m = INT_MAX;
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		kb[i] = make_kb(i);
		if (m > kb[i]) {
			m = kb[i];
			idx = i;
		}
	}
	cout << idx;
}