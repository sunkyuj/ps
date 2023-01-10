#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int h, w, n;

int main()
{
	FIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> h >> w >> n;
		int row=0, col=1;

		for (int i = 0; i < n; i++) {
			row++;
			if (row > h) {
				row = 1;
				col++;
			}
		}
		/*
		int jari;
		if (w < 10) {
			jari = 100;
		}
		else if (w < 100) {
			jari = 1000;
		}*/
		cout << row * 100 + col << "\n";
		
	}

}