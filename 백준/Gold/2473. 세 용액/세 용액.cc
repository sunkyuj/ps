#include <iostream>
#include <algorithm>
#include <limits.h>
#include <stdlib.h>


using namespace std;


typedef long long ll;

ll memo[5001][3]; //0 = abs val , 1=s, 2=e

ll arr[5001];

int main()
{
	for (int i = 0; i < 5001; i++) memo[i][0] = 3000000000;


	//-97 -6 -2 6 98
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	ll m = 3000000000;
	
	int I = 0, J = 1, K = 2;

	/*
	while (s < e) { //<-- not checking all the situation
		ll a = arr[s] + arr[e];

		memo[s][e] = a;

		if (a<0) s++;
		else if (a > 0) e--;
		else s++;
	}
	*/

	for (int i = 0; i < n - 2;i++) {
		int s = i+1, e = n - 1;
		while (s < e) {
			if (arr[i] + arr[s] + arr[e]< 0) {
				if (memo[i][0] > abs(arr[i] + arr[s] + arr[e])) {
					memo[i][0] = abs(arr[i] + arr[s] + arr[e]);
					memo[i][1] = s; memo[i][2] = e;
				}
				s++;
			}
			else { //(arr[i] + arr[s] + arr[e] >= 0)
				if (memo[i][0] > abs(arr[i] + arr[s] + arr[e])) {
					memo[i][0] = abs(arr[i] + arr[s] + arr[e]);
					memo[i][1] = s; memo[i][2] = e;
				}
				e--;
			}
		}
	}

	ll m2 = 3000000000;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (m2 > memo[i][0]) {
			m2 = memo[i][0];
			idx = i;
		}
	}

	cout << arr[idx] << " " << arr[memo[idx][1]] << " " << arr[memo[idx][2]];

}

/*
5
-5 -1 2 3 4
-5 2 3

but my answer is...

5
-5 -1 2 3 4
-5 2 4


*/