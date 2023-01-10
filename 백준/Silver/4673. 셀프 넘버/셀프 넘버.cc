#include <iostream>

using namespace std;

int memo[10001];

int d(int n) {
	int sum = n;
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
/*

33 을 d(33)=39 의 생성자

생  d(n)
91->101
100->101

*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 10000; i++) {
		int x = d(i);
		if(x<=10000) memo[d(i)]++;
	}
	for (int i = 1; i <= 10000; i++) if (memo[i] == 0) cout << i << "\n";
}
