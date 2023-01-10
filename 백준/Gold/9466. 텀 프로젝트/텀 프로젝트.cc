#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;


int n;

int pointing[100001]; // edge[a] = b  <=>  a->b
int cycle[100001]; // cycle yes == 1 // cycle no == -1 // not visited 0 //

bool visit[100001];
/*
bool has_cycle(int from, int cur) {
	visit[cur] = 1;
	int nxt = pointing[cur];

	if (from == nxt) {
		cycle[cur] = 1;
		return 1;
	}
	else if (visit[nxt] || cycle[nxt]) return 0;

	if (has_cycle(from, nxt)) {
		cycle[cur] = 1;
		return 1;
	}
	else return 0;
	
}
*/

int f(int cur, int c_orig) {
	visit[cur] = 1;
	int nxt = pointing[cur];

	if (nxt == pointing[nxt]) { // 막다른 길
		cycle[cur] = -1;
		cycle[nxt] = 1;
		
		return 0;
	}

	if (visit[nxt]) {
		if (cycle[nxt]) { //
			cycle[cur] = -1;
			return 0;
		}
		else { // make cycle stat
			cycle[cur] = 1;
			return nxt; // cycle origin
		}
		
	}

	c_orig = f(nxt, c_orig);

	if (c_orig == 0) {
		cycle[cur] = -1;
		return 0;
	}
	else if (c_orig == cur) {
		cycle[cur] = 1;
		return 0;
	}
	else {
		cycle[cur] = 1;
		return c_orig;
	}

	

}


int main()
{
	FIO;
	int T; cin >> T;
	while (T--) {
		memset(cycle, 0, sizeof(cycle));
		memset(visit, 0, sizeof(visit));
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> pointing[i];

		int cnt=0;
		for (int i = 1; i <= n; i++) {
			
			if (cycle[i]) continue;
			//if (!has_cycle(i, i)) cnt++;
			f(i,0);
			//
		}
		for (int i = 1; i <= n; i++) {
			if (cycle[i] == -1) cnt++;
		}
		cout << cnt<<"\n";
	}
}


/*
10
3
1 3 2
4
2 1 1 4

*/