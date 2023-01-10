#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <queue>
#include <cmath>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
int home_x, home_y, rock_x, rock_y;
vector<pair<int, int>> conv;//n
vector<int> visited;//n



int main()
{
	FIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		cin >> home_x >> home_y;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			conv.push_back({ x,y });
			visited.push_back(0);
		}
		cin >> rock_x >> rock_y;

		queue<pair<int, int>> q;
		q.push({ home_x, home_y});
		bool sad = true;

		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();

			if (abs(rock_x - x) + abs(rock_y - y) <= 1000) {
				cout << "happy\n";
				sad = false;
				break;
			}

			for (int i = 0; i < n; i++) {
				if (!visited[i] && abs(conv[i].first - x) + abs(conv[i].second - y) <= 1000) {
					q.push(conv[i]);
					visited[i] = 1;
				}
			}
		}
		

		if(sad) cout << "sad\n";

		conv.clear();
		visited.clear();
	}

}