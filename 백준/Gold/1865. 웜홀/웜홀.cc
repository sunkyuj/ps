#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 2000000000

using namespace std;

int n, m, w; //지점, 도로, 웜홀
//int road[2501][2501]; //start,end,time
//int wormhole[2501][2501]; //start,end,time
vector<pair<pair<int,int>, int>> edges; //edges ={ { from,to }, price }
int dist[501];

void input() {
	cin >> n >> m >> w;
	for (int i = 0; i < m; i++) { //road <-- non-dir!!!!!!!!!!!!!
		int s, e, t;
		cin >> s >> e >> t;
		edges.push_back({ { s,e },t });
		edges.push_back({ {e,s}, t });
	}
	for (int i = 0; i < w; i++) { //wormhole
		int s, e, t;
		cin >> s >> e >> t;
		edges.push_back({ { s,e }, -t });
	}
}

bool n_cycle(int start) {

	fill(dist, dist + n + 1, MAX);

	dist[start] = 0;

	for (int i = 1; i <= n-1; i++ ) {
		for (int j = 0; j < edges.size(); j++) {
			int from = edges[j].first.first;
			int to = edges[j].first.second;
			int price = edges[j].second;

			/*
			if (dist[from] == INT_MAX) continue;
			이 문제에서 음의 싸이클이 있는지를 파악해야하기 때문에 방문할 수 없는(시작점이랑 연결x) 점도
			검사를 해줘야 한다.
			안그러면 시작점이랑 연결 안된 점들이 음의 싸이클 이뤄도 이걸 찾을수가 없어서
			틀리게 된다.
			물론 이 함수 밖에서 모든 점에 대해서 n번 반복해도 되긴 하지만
			그러면 시간초과가 떠서 또 틀리게 된다...


			*/
			if (dist[to] > dist[from] + price) dist[to] = dist[from] + price;

		}
	}

	for (int j = 0; j < edges.size(); j++) {
		int from = edges[j].first.first;
		int to = edges[j].first.second;
		int price = edges[j].second;

		//if (dist[from] == INT_MAX) continue;
		if (dist[to] > dist[from] + price) { // has  cycle!
			return 1;
		}
	}
	return 0;
}

int main()
{
	FIO;
	int T;
	cin >> T;
	while (T--) {
		input();
		/*
		bool has_ncycle = false;
		
		for (int i = 1; i <= n-1; i++) {
			has_ncycle = has_ncycle || n_cycle(i);
			if (has_ncycle) {
				break;
			}
		}
		*/
		if (n_cycle(1)) cout << "YES\n";
		else cout << "NO\n";

		edges.clear();
	}

}