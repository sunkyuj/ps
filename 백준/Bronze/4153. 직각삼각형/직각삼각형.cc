#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int e[3];

int main()
{
	FIO;
	while (1) {
		cin >> e[0] >> e[1] >> e[2];
		if (e[0] == 0 && e[1] == 0 && e[2] == 0) break;
		sort(e, e + 3);
		if (e[0] * e[0] + e[1] * e[1] == e[2] * e[2]) cout << "right\n";
		else cout << "wrong\n";
	}
}