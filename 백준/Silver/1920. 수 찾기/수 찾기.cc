#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100001];

/*
int bins(int x) {

}
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (binary_search(arr, arr + n, x)) cout << "1\n";
		else cout << "0\n";
	}
}