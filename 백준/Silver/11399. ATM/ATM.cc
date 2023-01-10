#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
int arr[1001];
int accum[1001];

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	accum[0] = arr[0];
	int sum = accum[0];
	for (int i = 1; i < n; i++) {
		accum[i] = accum[i - 1] + arr[i];
		sum += accum[i];
	}
	cout << sum;
}
/*
1 2 3 4 5
3 1 4 3 2

3 4 8 11 13

2 5 1 4 3
1 2 3 3 4

1 3 6 9 13

*/