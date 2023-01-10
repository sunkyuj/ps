#include <iostream>

using namespace std;

typedef long long ll;

ll n, m;
ll arr[10001];
int main()
{
	cin >> n >> m;
	for (ll i = 0; i < n; i++) cin >> arr[i];

	int start = 0, end = 0;
	ll sum = arr[0];
	ll cnt = 0;
	while (end < n ) {
		if (sum < m) {
			sum += arr[++end];
		}
		else  {
			if (sum == m) cnt++;
			sum -= arr[start++];
		}
	}
	cout << cnt;

}
