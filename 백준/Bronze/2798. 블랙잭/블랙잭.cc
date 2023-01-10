#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[101];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	sort(arr, arr + n);
	int M = 0;

	for (int i = n - 1; i >= 2; i--) {
		for (int j = i - 1; j >= 1; j--) {
			for (int k = j - 1; k >= 0; k--) {
				if (arr[i] + arr[j] + arr[k] <= m && M < arr[i] + arr[j] + arr[k]) {
					M = arr[i] + arr[j] + arr[k];
				}
			}
		}
	}
	cout << M;

}
