#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
typedef long long ll;

ll k, n;

ll len[10001];



int main()
{
	FIO;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> len[i];
	}
	sort(len, len + k);

	ll s = 1, e = len[k-1];
	
	ll greatest = 0;
	while (s<=e) {
		ll mid = (s + e) / 2;
		if (mid == 0) break;

		ll cnt = 0;

		for (int j = 0; j < k; j++) {
			cnt += len[j] / mid;
		}

		if (cnt >= n) {
			greatest = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	cout << greatest;
}