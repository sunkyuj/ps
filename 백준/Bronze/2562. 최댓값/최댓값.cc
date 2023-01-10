#include <iostream>

using namespace std;

int main()
{
	int m = 0,mi=0;
	for (int i = 1; i <= 9; i++) {
		int x;
		cin >> x;
		if (x > m) {
			m = x; mi = i;
		}
	}
	cout << m << "\n" << mi;
}
