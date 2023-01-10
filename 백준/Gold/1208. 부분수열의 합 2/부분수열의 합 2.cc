#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <map>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n, s;
int arr[41];
int half;
map<int, int> mp; //mp[sum] = cnt
long long ans;

void L(int idx, int sum) {
	if (idx == half) {
		mp[sum]++;
		return;
	}
	L(idx + 1, sum); // exclude arr[idx]
	L(idx + 1, sum + arr[idx]); // include arr[idx]

}
void R(int idx, int sum) {
	if (idx == n) {
		ans += mp[s - sum];
		return;
	}
	R(idx + 1, sum);
	R(idx + 1, sum + arr[idx]);
}

int main()
{
	FIO;
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	half = n / 2;

	L(0, 0);
	R(half, 0);
	if (s == 0) ans--;
	cout << ans;

}