#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int board[10][10];
int m = INT_MAX;
int papers[6] = { 0,5,5,5,5,5 };

bool in_range(int y, int x) { return y >= 0 && x >= 0 && y < 10 && x < 10; }

int get_max_sqr(int y, int x) {
	int len = 1, new_y = y, new_x = x;
	while (len < 5 && in_range(new_y + 1, new_x + 1)) {
		new_y++; new_x++;
		for (int i = new_y; i >= y; i--) if (board[i][new_x] == 0) return len;
		for (int j = new_x; j >= x; j--) if (board[new_y][j] == 0) return len;
		len++;
	}
	return len;
}

void put(int y, int x, int len) {
	for (int i = y; i < y + len; i++) for (int j = x; j < x + len; j++) board[i][j] = 0;
}
void undo(int y, int x, int len) {
	for (int i = y; i < y + len; i++) for (int j = x; j < x + len; j++) board[i][j] = 1;
}

int dfs() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] == 1) {
				int len = get_max_sqr(i, j);
				bool has_case = false;
				int small = INT_MAX;

				for (int l = len; l >= 1; l--) {
					if (papers[l] == 0) continue;

					put(i, j, l);
					papers[l]--;

					int tmp = dfs();

					undo(i, j, l);
					papers[l]++;

					if (tmp == -1) continue;
					small = min(small, tmp);
					has_case = true;

				}

				if (has_case) return small + 1;
				else return -1;
			}
		}
	}
	return 0; // all 0
}

int main()
{
	FIO;
	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) cin >> board[i][j];

	cout << dfs();
}

/*

0 0 0 0 0 0 0 0 0 0
1 1 1 0 1 1 0 0 0 0
1 1 1 1 1 1 0 0 0 0
1 1 1 1 1 0 0 0 0 0
1 1 1 1 1 1 0 0 0 0
1 1 1 1 1 1 0 0 0 0
1 1 1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

무조건 큰걸로 하면 안되는 이유
5 짜리 넣으면 10
5 없이 하면 7




1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 0 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 0 0 0 0
*/