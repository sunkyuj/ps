#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n, s;
int arr[100001];

int main()
{
	FIO;
	cin >> n >> s;
	int total = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
	}
	if (total < s) {
		cout << 0;
		return 0;
	}
	
	int ml = 100001;
	//len=r-l+1

	
	int l = 0, r = 0;
	int sum = arr[0];
	while (l < n && r < n && l <= r) {
		int len = r - l + 1;
		if (sum >= s && len < ml) ml = len;

		if (sum < s) {
			if (r + 1 < n) sum += arr[++r];
			else break;
		}
		else sum -= arr[l++];
	}
	cout << ml;

}

