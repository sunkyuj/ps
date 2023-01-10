#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n;
vector<int> v[100001];
int visit[100001];
int par[100001];

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
	queue<int> q;
	q.push(1);
	visit[1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i];
			if (!visit[nxt]) {
				par[nxt] = cur;
				q.push(nxt);
				visit[nxt] = 1;
			}
		}
	}
	
	for (int i = 2; i <= n; i++) cout << par[i] << "\n";
}