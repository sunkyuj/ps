#include <iostream>

using namespace std;

string s;


int main()
{

	int T;
	cin >> T;
	
	
	while (T--) {
		cin >> s;
		int status = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') status++;
			else status--;

			if (status < 0) {
				break;
			}
		}
		if (status == 0) cout << "YES\n";
		else cout << "NO\n";
	
	}

}