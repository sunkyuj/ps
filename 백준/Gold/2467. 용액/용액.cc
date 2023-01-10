#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>
using namespace std;


typedef long long ll;

int n;
ll arr[100001];



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll m = INT_MAX;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	int s = 0, e = n - 1;
	int ms=0, me=n-1;

	while (s != e) {
		ll sum = arr[s] + arr[e];
		if (sum < 0) {
			if (abs(sum) < m) {
				m = abs(sum);
				ms = s; me = e;
			}
			s++;
		}
		else if (sum > 0) {
			if (sum < m) {
				m = sum;
				ms = s; me = e;
			}
			e--;
		}
		else {
			//m = sum;
			ms = s; me = e;
			break;
		}
	}	
	cout << arr[ms] << " " << arr[me];

}


/*

sort(arr, arr + n);

	for (int i = 0; i < n - 1; i++) {

		for (int j = i + 1; j < n; j++) {
			if (j>i+1&&abs(arr[i] + arr[j]) >= abs(arr[i] + arr[j - 1])) break;
			if (abs(arr[i] + arr[j]) < m) {
				m = abs(arr[i] + arr[j]);
				I = i; J = j;

			}
		}
	}
	cout << arr[I] << " " << arr[J];

*/
