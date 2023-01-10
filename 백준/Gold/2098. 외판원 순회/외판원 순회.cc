#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n;
int w[17][17];
//bool visit[17];
//int CNT = 0;
int ans = 20000000;
int d[17][1 << 16]; // d[v][S] -> v번 노드에서 출발, 집합 S 를 거쳐 0에 도착
// 부분집합을 비트로 생각해보자.

bool in(int subset, int j) {
	return subset & (1 << j);
}

int diff(int subset, int j) {
	return subset - (1 << j);
}

//int count() {

//}
//구해야할 것 : d[ 0 ][ S-{0} ]
/*
f(i,S) = min( k: 1~n-1 -> f(k,S-{i}) )
f(i,NULL) = w[i][0]
*/
int f(int cur, int subset) {
	
	if (d[cur][subset]) return d[cur][subset];

	int m = 20000000;
	for (int j = 1; j < n; j++) {
		if (w[cur][j] == 0 || !in(subset, j)) continue;
		m = min(m, w[cur][j] + f(j, diff(subset, j)));
	}
	return d[cur][subset] = m;
}

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> w[i][j];
	}
	
	//visit[0] = 1;
	//ans = f(0, 1);
	for (int i = 1; i < n; i++) d[i][0] = w[i][0]; //공집합
	cout << f(0, diff((1 << n) - 1, 0));
	
	//cout << ans;
	//cout << "\n" << CNT;
}
/*

16
0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0


2 4
3 15
4 64
5 325
6 1956
7 13699
*/

/*
void dfs(int cur, int start, int cnt, int sum) {
	//CNT++;
	if (ans < sum) return;
	if (cnt == n) {
		if (w[cur][start] && ans > sum + w[cur][start]) ans = sum + w[cur][start];
		return;
	}

	for (int j = 0; j < n; j++) {
		if (w[cur][j]&&!visit[j]) {
			visit[j] = 1;
			dfs(j, start, cnt + 1, sum + w[cur][j]);
			visit[j] = 0;
		}
	}
}
*/
/*
int f(int cur,int cnt) {
	CNT++;
	//if (dp[cur]) return dp[cur];
	if (cnt == n) return dp[cur]=w[cur][0]; //else return; 어차피 순회할 수 있는 경우만 입력으로 주어짐

	int m = 20000000;
	for (int j = 0; j < n; j++) {
		if (w[cur][j] && !visit[j]) {
			visit[j] = 1;
			m = min(m, w[cur][j] + f(j, cnt + 1));
			visit[j] = 0;
		}
	}
	return dp[cur] = m;
}*/