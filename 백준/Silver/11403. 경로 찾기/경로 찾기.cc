#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
int arr[101][101];
int ans[101][101];


int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> arr[i][j];
	}
	
	for (int i = 0; i < n; i++) {
		queue <int> q;
		bool visited[101][101] = { 0 };

		for (int j = 0; j < n; j++) {
			if (arr[i][j]) {
				q.push(j);
				visited[i][j] = 1;
			}
		}

		
		while (!q.empty()) {
			int to = q.front();
			ans[i][to] = 1;
			for (int j = 0; j < n; j++) {
				if (arr[to][j] && !visited[to][j]) {
					q.push(j);
					visited[to][j] = 1;
				}
			}

			q.pop();
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << ans[i][j] << " ";
		cout << "\n";
	}
}
/*

7
1 0 0 1 1 1 1
0 0 0 0 0 0 1
0 0 0 0 0 0 0
1 0 0 0 1 1 1
1 0 0 0 0 0 0
0 0 0 0 0 0 1
0 0 1 0 0 0 0

*/