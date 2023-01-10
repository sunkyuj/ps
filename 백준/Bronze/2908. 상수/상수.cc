#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;



int main()
{
	FIO;
	string a,b;
	cin >> a >> b;
	
	swap(a[0], a[2]);
	swap(b[0], b[2]);

	if (a > b) cout << a;
	else cout << b;
}