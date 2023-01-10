#include <iostream>

using namespace std;

int n;

int is_dg(int x) {
	int bsum = x;
	while (x) {
		bsum += x%10;
		x /= 10;
	}
	if (bsum == n) return 1;
	else return 0;
}

/*
245 -> 245+2+4+5 = 256
245의 분해합은 256, 따라서 245는 256의 생성자

abc분해합 = abc + a + b + c
*/


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (is_dg(i)) {
			cout << i;
			return 0;
		}
	}
	cout << 0;

}
