#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;


int main()
{
	FIO;
	int n;
	cin >> n;
	cout << n / 5 + n / 25 + n/125;
}
/*
int n;
	cin >> n;
	cout << n / 5;
*/