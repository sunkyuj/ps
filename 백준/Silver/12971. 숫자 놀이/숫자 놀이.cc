#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int p1, p2, p3, x1, x2, x3; //1~300, pi>xi

int f() {
	for (int i = 1; i <= p1*p2*p3; i++) {
		if (i % p1 == x1 && i % p2 == x2 && i % p3 == x3) return i;
	}
	return -1;
}

int main()
{
	FIO;
	cin >> p1 >> p2 >> p3 >> x1 >> x2 >> x3;
	cout << f();
}