#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;


//typedef long long ll;

int n;
int arr[100001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int s = 0, e = n - 1;
	int I=0, J=1;
	int m = 2000000001;

	while (s < e) {

		if (arr[s] + arr[e] < 0) {
			if (abs(arr[s] + arr[e]) < m) {
				m = abs(arr[s] + arr[e]);
				I = s;
				J = e;
			}
			s++; 
		}
		else if (arr[s] + arr[e] > 0) { 
			if (abs(arr[s] + arr[e]) < m) {
				m = abs(arr[s] + arr[e]);
				I = s;
				J = e;
			}
			e--; 
		}

		else {
			I = s; 
			J = e;
			break;
		}


	}
	cout << arr[I] << " " << arr[J];
}
