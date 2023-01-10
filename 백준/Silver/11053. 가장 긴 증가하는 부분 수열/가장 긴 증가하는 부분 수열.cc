#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1001];
int maxL = 0;

int memo[1001];



int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) memo[i] = 1;
	
	for (int i = 0; i < n; i++) {
		int M = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (M <= memo[j]) M = memo[j] + 1;
			}
		}
		memo[i] = M;
	}

	for (int i = 0; i < n; i++) {
		if (memo[i] > maxL) maxL = memo[i];
	}
	cout << maxL;
	
}
/*

 A = {10, 20, 7, 10, 25, 30, 20, 50,}

 */