#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

typedef long long ll;
typedef struct ITEM {
	int m, v;
	bool operator<(ITEM& x) {
		return m < x.m;
	}

}ITEM;

ll n, k, c[300001];
ITEM item[300001];


int main()
{
	FIO;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) cin >> item[i].m >> item[i].v;
	for (int i = 0; i < k; i++) cin >> c[i];

	sort(item, item + n); //무게! 오름차순으로 정렬 <- 어차피 우선순위큐에서 가격 높은순으로 정렬해줌
	sort(c, c + k); // 가방 최대무게 오름차순으로 정렬
	
	
	ll sum = 0;
	priority_queue <ll> pq; // v

	int idx = 0;

	//O(k + n)
	for (int i = 0; i < k; i++) {
		while(idx<n && item[idx].m <= c[i]) {
			pq.push(item[idx].v);
			idx++;
		}

		if (pq.empty()) continue;
		sum += pq.top();
		pq.pop();	
	}
	cout << sum;
}