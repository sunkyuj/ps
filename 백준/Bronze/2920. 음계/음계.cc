#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;



int main()
{
	FIO;
	int arr[8];
	for (int i = 0; i < 8; i++) cin >> arr[i];
	
	if (arr[0] == 1) {
		int i = 0;
		for (i = 0; i < 8; i++) {
			if (arr[i] != i + 1) break;
		}
		if (i == 8) {
			cout << "ascending";
			return 0;
		}
	}
	else if (arr[0] == 8) {
		int i = 0;
		for (i = 0; i < 8; i++) {
			if (arr[i] != 8-i) break;
		}
		if (i == 8) {
			cout << "descending";
			return 0;
		}
	}
	
	cout << "mixed";
	return 0;

}