#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cmath>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
int arr[500001];
int cnt[8001];

int main()
{
	FIO;
	cin >> n;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		cnt[arr[i] + 4000]++;
	}
	sort(arr, arr + n);
	int avg = round(sum / n);
	int mid = arr[n / 2];
	
	int M = 0;
	int same_cnt = 0;
	int many;
	for (int i = 0; i < 8001; i++) {
		if (cnt[i] == 0) continue;

		if (cnt[i] >= M) {
			if (cnt[i] == M) {
				if (same_cnt != 0) continue;
				same_cnt++;
				M = cnt[i];
				many = i - 4000;
			}
			else {
				M = cnt[i];
				many = i - 4000;
				same_cnt = 0;
			}
		}
	}

	int range = arr[n - 1] - arr[0];

	cout << avg << "\n" << mid << "\n" << many << "\n" << range;
	
}