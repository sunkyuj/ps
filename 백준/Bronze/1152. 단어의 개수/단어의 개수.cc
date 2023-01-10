#include <iostream>
#include <string>


using namespace std;

string s;
int cnt = 0;

int main()
{
	s.reserve(1000004);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	getline(cin,s);
	
	while (!s.empty()&&s[0] == ' ') s.erase(0, 1);
	while (!s.empty()&&s[s.size() - 1] == ' ') s.erase(s.size() - 1, s.size());
	int i;
	for ( i = 0; i < s.size(); i++) {
		if (s[i] == ' ') cnt++;
	}
	//cout << i << "\n";

	if (s.empty()) cout << 0;
	else cout << cnt + 1;
}
