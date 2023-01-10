#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
int w = 0, b = 0;
int arr[129][129];

int all_same(int si, int sj, int ei, int ej) {
	for (int i = si; i <= ei; i++) {
		for (int j = sj; j <= ej; j++) {
			if (arr[si][sj] != arr[i][j]) return -1;
		}
	}
	return arr[si][sj]; // 0 w // 1 b
}

void div(int si, int sj, int ei, int ej) {
	int same = all_same(si, sj, ei, ej);
	if (same == -1) {
		div(si, sj, (si + ei) / 2, (sj + ej) / 2); //
		div(si, (sj + ej) / 2 + 1, (si + ei) / 2, ej); // si=same, sj=half+1, ei=half, ej=same 
		div((si + ei) / 2 + 1, sj, ei, (sj + ej) / 2); // si=half+1, sj=same, ei=same, ej=half
		div((si + ei) / 2 + 1, (sj + ej) / 2 + 1, ei, ej); // si=half+1, sj=half+1, ei=same, ej=same
	}
	else if (same == 0) { //w
		w++;
		return;
	}
	else { //b
		b++;
		return;
	}
}

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> arr[i][j];
	}
	
	div(0, 0, n - 1, n - 1);
	cout << w << "\n" << b;
}