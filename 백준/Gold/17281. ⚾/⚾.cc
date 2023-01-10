#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n, M = 0;
int inning[51][9];

void get_score(vector<int> order) {
	order.insert(order.begin() + 3, 0);
	int score = 0;
	int order_idx = 0;

	for (int i = 0; i < n; i++) {

		int out = 0;
		int b1 = 0, b2 = 0, b3 = 0;

		while (out < 3) {

			int hit = inning[i][order[order_idx]];

			if (hit == 0) out++;
			else if (hit == 1) {
				score += b3;
				b3 = b2;
				b2 = b1;
				b1 = 1;
			}
			else if (hit == 2) {
				score += b3 + b2;
				b3 = b1;
				b2 = 1;
				b1 = 0;
			}
			else if (hit == 3) {
				score += b3 + b2 + b1;
				b3 = 1;
				b2 = 0;
				b1 = 0;
			}
			else {
				score += b3 + b2 + b1 + 1;
				b3 = 0;
				b2 = 0;
				b1 = 0;
			}

			order_idx = (order_idx + 1) % 9;
		}
	}
	if (M < score) M = score;
}

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) cin >> inning[i][j];
	}
	vector<int> order{ 1,2,3,4,5,6,7,8 };
	do {
		get_score(order);
	} while (next_permutation(order.begin(), order.end()));

	cout << M;
}