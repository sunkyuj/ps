#include <iostream>

using namespace std;

string s;
int main()
{
	while (1) {
		cin >> s;
		if (s == "0") break;
		int i;
		for (i = 0; i < s.size() / 2; i++) {
			if (s[i] != s[s.size() - 1 - i]) break;
		}
		if (i == s.size()/2) cout << "yes\n";
		else cout << "no\n";
	}
}
