#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

vector<int> lis;
vector<int> lds;

int n, arr[1001];

int bin(int s, int e, int key) {
	while (s <= e) {
		int mid = (s + e) / 2;
		if (lds[mid] > key) s = mid + 1;
		else e = mid - 1;
	}
	return s;
}

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	lis.push_back(arr[0]);
	lds.push_back(arr[n-1]);

	vector<int> inc, dec;
	inc.push_back(1);
	dec.push_back(1); // stack, use pop to get val

	for (int i = 1; i < n; i++) {
		if (arr[i] > lis.back()) lis.push_back(arr[i]);
		else {
			vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), arr[i]);
			*it = arr[i];
		}
		inc.push_back(lis.size());
		
		int arrn_1_i = arr[n - 1 - i], ldsback = lds.back();
		if (arr[n-1-i] > lds.back()) lds.push_back(arr[n-1-i]);
		else {
			
			vector<int>::iterator it = lower_bound(lds.begin(), lds.end(), arr[n-1-i]);
			*it = arr[n-1-i];
		}
		dec.push_back(lds.size());
	}

	int M = 0;
	for (int i = 0; i < n; i++) {
		if (M < inc[i] + dec[n - 1 - i]) M = inc[i] + dec[n - 1 - i];
	}
	cout << M - 1;

	
	/*
	for (int i = 0; i < n; i++) cout << inc[i] << " ";
	cout << "\n";
	for (int i = 0; i < n; i++) cout << dec[i] << " ";
	*/
}