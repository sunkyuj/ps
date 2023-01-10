#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int arr[1000001];
int M=INT_MIN, m=INT_MAX;
int main()
{
	FIO;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > M) M = arr[i];
		if (arr[i] < m) m = arr[i];
	}
	cout << m << " " << M;
}