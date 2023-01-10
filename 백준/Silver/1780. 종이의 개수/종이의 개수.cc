#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cmath>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int arr[2188][2188];
int m1 = 0, p1 = 0, zero = 0;
int n;


int all_same(int size, int y, int x) {
	for (int i = y; i < y+size; i++) {
		for (int j = x; j < x+size; j++) if (arr[y][x] != arr[i][j]) return 2;
	}
	return arr[y][x];
}

void f(int size, int y, int x) {
	if (size == 0) return;
	int same = all_same(size,y,x);
	if (same == -1) {
		m1++;
		return;
	}
	else if (same == 0) {
		zero++;
		return;
	}
	else if (same == 1) {
		p1++;
		return;
	}
	else { 
		f(size / 3, y, x);
		f(size / 3, y, x+size/3);
		f(size / 3, y, x + size / 3 * 2);
		
		f(size / 3, y + size / 3, x);
		f(size / 3, y + size / 3, x + size / 3);
		f(size / 3, y + size / 3, x + size / 3 * 2);

		f(size / 3, y + size / 3 * 2, x);
		f(size / 3, y + size / 3 * 2, x + size / 3);
		f(size / 3, y + size / 3 * 2, x + size / 3 * 2);
	}
}

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> arr[i][j];
	}

	f(n,0,0);

	cout << m1 << "\n" << zero << "\n" << p1 << "\n";
}
/*
-1 : 1+9 =10
0  : 3+9 =12
1  : 2+9 =11


*/