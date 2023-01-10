#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

typedef long long ll;

ll a, b;

int main()
{
	FIO;
	cin >> a >> b;
	

	priority_queue<pair<ll, ll>> pq;
	pq.push({ a,0 });
	while (!pq.empty()) {
		ll x = pq.top().first, len=pq.top().second;
		pq.pop();
		if (x > b) continue;
		if (x == b) {
			cout << len+1;
			return 0;
		}

		pq.push({ x * 2,len + 1 });
		pq.push({ x *10 + 1,len + 1 });
	}

	cout << -1;

}