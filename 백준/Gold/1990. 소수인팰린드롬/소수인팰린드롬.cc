#include <iostream>

using namespace std;

int a, b;

bool is_prime(int x) {
	for (int i = 2; i*i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

bool is_pal(int x) {
	string s;

	while (x) {
		s += x % 10 + '0';
		x /= 10;
	}
	int l = s.size();

	for (int i = 0; i < l / 2; i++) {
		if (s[i] != s[l - 1 - i]) return false;
	}
	return true;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;


	int jari = 1;
	while (jari * 10 <= a) jari *= 10;

	if (a % 2 == 0) a++;


	for (int i = a; i <= b; i+=2) {
		if (jari * 10 <= i) jari *= 10;
		if (jari == 1000 || jari == 100000 || jari == 10000000) {
			i = jari * 10 - 1;
			continue;
		}
		if ((i / jari) % 2 == 0) {
			i += jari-2;
			continue;
		}


		if (is_pal(i)&&is_prime(i)) cout << i << "\n";
		
	}
	cout << -1;

}
