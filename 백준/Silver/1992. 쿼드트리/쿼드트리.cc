#include <iostream>
#include <algorithm>
#include <limits.h>
#include <stack>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
string arr[64];
string s="";

int all_same(int size, int y, int x) {
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) if (arr[i][j] != arr[y][x]) return -1;
	}
	return arr[y][x]-'0'; //0 or 1
}

//     ( 0 (0011) (0(0111)01) 1 )

void f(int size,int y,int x) {
	if (size <= 0) return;
	int same = all_same(size, y, x);
	if (same == 0) {
		s += "0";
		return;
	}
	else if (same == 1) {
		s += "1";
		return;
	}
	else {
		s += "(";
		f(size / 2, y, x);
		f(size / 2, y, x+size/2);
		f(size / 2, y+size/2, x);
		f(size / 2, y+size/2, x+size/2);
		s += ")";
	}
}

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	f(n, 0, 0);
	cout <<s;
}