#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;



int main()
{
	FIO;
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int x;
		cin >> x;
		sum += x * x;
	}
	cout << sum % 10;

}