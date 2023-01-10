#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int arr[15][15];
int n;


int able(int y,int x) {
	for (int i = 0; i < n; i++) {
		if (arr[i][x]) return 0;
	}

	for (int j = 0; j < n; j++) {
		if (arr[y][j]) return 0;
	}

	int i = y, j = x;
	
	while (i >= 0 && j < n) {//1
		if (arr[i][j]) return 0;
		i--; j++;
	}
	i = y, j = x;
	while (i < n && j >= 0) {//3
		if (arr[i][j]) return 0;
		i++; j--;
	}

	i = y, j = x;
	while (i >= 0 && j >= 0) {//2
		if (arr[i][j]) return 0;
		i--; j--;
	}
	i = y, j = x;
	while (i < n && j < n) {//4
		if (arr[i][j]) return 0;
		i++; j++;
	}

	return 1;
}


int f(int y) {

	if (y == n) return 1;

	int sum = 0;
	for (int x = 0; x < n; x++) {
		if (able(y, x)) {
			arr[y][x] = 1;
			sum += f(y + 1);
			arr[y][x] = 0;
		}
	}
	return sum;
}

int main()
{
	FIO;
	cin >> n;
	cout << f(0);
}