#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n, m, b; //b<=64,000,000
int ground[501][501];
int t[258];
int b_need[258];

/*
블럭 제거는 2초
블럭 꺼내서 놓기는 1초
*/
int all_same() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (ground[i][j] != ground[0][0]) return 0;
	}
	return 1;
}

int cut(int h) {
	int extra = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ground[i][j] > h) {
				extra += ground[i][j] - h;
				t[h] += 2 * (ground[i][j] - h);
			}
		}
	}
	return extra;

}

int main()
{
	FIO;
	
	cin >> n >> m >> b;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> ground[i][j];
	}
	if (all_same()) {
		cout << 0 <<" "<< ground[0][0];
		return 0;
	}

	for (int h = 0; h <= 256; h++) {
		int extra = cut(h);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(ground[i][j] < h){ //ground is lower -> add(b)
					t[h] += h - ground[i][j];
					b_need[h] += h - ground[i][j];
				}
			}
		}
		if (b_need[h] > b+extra) {
			t[h] = 0;
			b_need[h] = 0;
			break;
		}
	}
	int min_ans = INT_MAX;
	int max_h = 0;
	for (int h = 0; t[h] != 0; h++) {
		if (min_ans >= t[h]) {
			min_ans = t[h];
			max_h = h;
		}
	}
	cout << min_ans << " " << max_h;
}