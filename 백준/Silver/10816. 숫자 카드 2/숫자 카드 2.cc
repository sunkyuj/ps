#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n, m;
int arr[20000001];


int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[10000000 + x]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cout << arr[10000000 + x] << " ";
	}
}