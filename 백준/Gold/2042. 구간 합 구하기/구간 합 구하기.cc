#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

typedef long long ll;
int n, m, k;
//2,097,152
ll arr[1000001];
vector<ll> tree(2097153);

ll init(int tree_idx, int start, int end) {
	if (start == end) return tree[tree_idx] = arr[start];

	int mid = (start + end) / 2;
	return tree[tree_idx] = init(tree_idx * 2, start, mid) + init(tree_idx * 2 + 1, mid + 1, end);

}

void update(int idx,int tree_idx, int start, int end, ll diff) {
	if (!(start <= idx && idx <= end)) return;

	tree[tree_idx] += diff;

	if (start == end) return;

	int mid = (start + end) / 2;
	update(idx, tree_idx * 2, start, mid, diff);
	update(idx, tree_idx * 2 + 1, mid + 1, end, diff);
	
}

ll sum(int tree_idx, int start, int end, int left, int right) {
	int mid = (start + end) / 2;
	if (end < left || right < start) return 0;
	else if (left <= start && end <= right) return tree[tree_idx];

	return sum(tree_idx * 2, start, mid, left, right) + sum(tree_idx * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	FIO;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1,1,n);
	for (int i = 0; i < m+k; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) { //update
			ll diff = c - arr[b];
			update(b, 1, 1, n, diff);
			arr[b] = c;
		}
		else { // print sum
			cout << sum(1, 1, n, b, c) << "\n";
		}
	}
}