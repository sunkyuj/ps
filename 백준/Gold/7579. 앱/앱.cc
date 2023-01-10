#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

typedef struct ITEM {
	int m,c;

	bool operator<(ITEM& other) {
		//if (c == other.c) return m > other.m;
		return c < other.c;
	}
}ITEM;

int n, M;
ITEM item[101];
//int cidx[101];
int dp[10001]; // dp[cost] = m
//int ans = 10001;
/*
c = 0 로 만들수 있는 최대값 
c = 1 로 만들수 있는 최대값
c = 2 로 만들수 있는 최대값
c = 3 로 만들수 있는 최대값

c = x 로 만들수 있는 최대값

*/

/*
int f(int idx,int msum, int csum) {

	if (dp[idx]) return dp[idx];
	if (msum >= M && csum < ans) {
		ans = csum;
		return 0;
	}

	if (idx == n) return 0;

	dp[csum + item[idx].c] = max(dp[csum + item[idx].c],f(idx + 1, msum + item[idx].m, csum + item[idx].c));
	dp[csum] = max(dp[csum], f(idx + 1, msum, csum));

	return max(dp[csum + item[idx].c], dp[csum]);

}*/

int main()
{
	FIO;
	cin >> n >> M;
	int sum = 0;
	for (int i = 0; i < n; i++) cin >> item[i].m;
	for (int i = 0; i < n; i++) {
		cin >> item[i].c;
		sum += item[i].c;
	}
	//for (int i = 0; i < n; i++) {
		//if (item[i].c == 0) dp[0] += item[i].m; // dp[0] 만들어주기
	//}

	// dp[cost] = m
	for (int i = 0; i < n; i++) {
		for (int j = sum; j >= item[i].c; j--) {
			dp[j] = max(dp[j], dp[j - item[i].c] + item[i].m);
		}
	}

	for (int C = 0; C <= sum; C++) {
		if (dp[C] >= M) {
			cout << C;
			break;
		}
	}


	//sort(item, item + n);
	//int x = f(0, 0, 0);
	//cout << ans;
	//cout << f(0, 0, 0);
	
}

/*
	fill(cidx, cidx + 101, -1);
	int cc = -1;
	for (int i = 0; i < n; i++) {
		if (item[i].c == 0) memo[0] += item[i].m; // memo[0] 만들어주기
		if (item[i].c != cc) { // c가 처음 나오는 인덱스들을 골라내자
			cc = item[i].c;
			cidx[cc] = i;
		}
	}

	//for (int i = 0; item[i].c == 0; i++) memo[0] += item[i].m;

	//int csum = 0;
	for (int C = 1; C <= 10000; C++) {
		for (int i = 1; i <= C; i++) {
			if (memo[C - i] == 0 || cidx[i] == -1) continue;
			memo[C] = max(memo[C], memo[C - i] + item[cidx[i]].m);
		}
		if (memo[C] >= M) {
			cout << C;
			return 0;
		}
	}
	*/