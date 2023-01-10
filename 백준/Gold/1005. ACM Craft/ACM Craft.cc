#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int T;
int n, k;
int arr[1001];
vector<int> req[1001];
vector<int> to_v[1001];
int w;

int inDegree[1001];
int time_sum[1001];

int dp[1001];

//int dist[1001];

/*

int f(int target) { //TLE

	if (dp[target]) return dp[target];

	int cost = arr[target];
	int M = 0;

	for(auto& x : req[target]) {
		int m = f(x);
		if (M < m) M = m;
	}

	cost += M;

	return dp[target]=cost;
}*/


int main()
{
	FIO;
	cin >> T;
	while (T--) {

		
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		for (int i = 1; i <= k; i++) {
			int need, target;
			cin >> need >> target;
			to_v[need].push_back(target);
			req[target].push_back(need);
			inDegree[target]++;
		}
		cin >> w;


		queue<int> q;

		for (int i = 1; i <= n; i++) if (inDegree[i] == 0) q.push(i);

		for (int i = 1; i <= n; i++) {
			int cur = q.front();
			q.pop();

			int prev_sum = 0;
			for (auto& x : req[cur]) { // 전에 애들 중 제일 큰거 넣어줌
				if (prev_sum < time_sum[x]) prev_sum = time_sum[x];
			}

			time_sum[cur] = arr[cur] + prev_sum;
			if (cur == w) {
				cout << time_sum[cur] << "\n";
				break;
			}

			for (int j = 0; j < to_v[cur].size(); j++) {
				int to = to_v[cur][j];

				if (--inDegree[to] == 0) q.push(to);
			}
		}

		


		//cout<<f(w)<<"\n";
	
		memset(req, 0, sizeof(req));
		memset(to_v, 0, sizeof(req));
		memset(inDegree, 0, sizeof(inDegree));
		memset(time_sum, 0, sizeof(time_sum));
		//memset(dp, 0, sizeof(dp));
	}

}
