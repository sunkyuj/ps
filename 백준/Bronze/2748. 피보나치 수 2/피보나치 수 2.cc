#include <iostream>

using namespace std;
long long m[100] = { 0,1,1 };

int main()
{
	long long n;
	cin >> n;

	for (long long i = 3; i <= n; i++) {
		m[i] = m[i - 1] + m[i - 2];
	}
	cout << m[n];
}
