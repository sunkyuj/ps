#include <iostream>
#include <string>
using namespace std;

string s;

int alp[26];

int main()
{
	s.reserve(1000002);
	cin >> s;
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a') s[i] -= 32;
		alp[s[i] - 'A']++;
	}

	int m=0, prev_m=0,idx;
	for (int i = 0; i < 26; i++) {
		if (alp[i] >= m) {
			prev_m = m;
			m = alp[i];
			idx = i;
		}
	}
	if (prev_m == m) cout << "?";
	else cout << (char)(idx + 'A');
}
