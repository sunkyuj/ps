#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef long long ll;

ll n, m;
ll tree[1000001];

int main()
{
	FIO;
	cin >> n >> m;
	for (ll i = 0; i < n; i++) cin >> tree[i];

	sort(tree, tree + n);
	
	ll s = 0, e = tree[n - 1]; //can't div with 0!!!!!
	ll max_h = 0;

	while (s <= e) {
		ll mid = (s + e) / 2;
		ll cut = 0;
		for (ll i = 0; i < n; i++) {
			if (tree[i] - mid > 0) cut += tree[i] - mid;
		}
		if (cut >= m) {
			max_h = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	cout << max_h;



	// 10 15 17 20


}