#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <queue>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;



int main()
{
	FIO;
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m; // n==문서의 개수,  m== 현재 큐에서 몇번째에 놓여있는지
		vector <int> v;
		priority_queue <int> pq;
		for (int i = 0; i < n; i++) {
			int pri;
			cin >> pri;
			v.push_back(pri);
			pq.push(pri);
		}

		int cnt = 0;
		while (!v.empty()) {
			if (v[0] == pq.top()) {
				cnt++;
				if (m == 0) {
					cout << cnt << "\n";
					break;
				}
				else {
					v.erase(v.begin());
					pq.pop();
					m--;
				}
			}
			else {
				if (m == 0) {
					m = v.size() - 1;
					v.push_back(v[0]);
					v.erase(v.begin());
				}
				else {
					m--;
					v.push_back(v[0]);
					v.erase(v.begin());
				}
			}
		}

	}
	
}
