#include <iostream>
#include <algorithm>
#include <limits.h>
#include <map>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
//10^9 == 1000000000 == 10억
int n;
int arr[1000001];
int	cop[1000001];
map <int, int> m;

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cop[i] = arr[i];
	}
	sort(cop, cop + n);

	int left = 0;
	m.insert({ cop[0], left });

	for (int i = 1; i < n; i++) {
		if (m.find(cop[i]) == m.end()) { //new
			m.insert({ cop[i], ++left });
		}
	}
	for (int i = 0; i < n; i++) cout<<m.find(arr[i])->second<<" ";

}
//-10 -9 2 4 4
//  0  1 2 3 3