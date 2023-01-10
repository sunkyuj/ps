#include <iostream>
#include <algorithm>
#include <limits.h>
#include <unordered_map>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n, m; //1~100000
string plist[100001];
unordered_map <string, int> um;

int s2i(string s) {
	int num = 0;
	int jari = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		num += (s[i] - '0') * jari;
		jari *= 10;
	}
	return num;
}

int main()
{
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> plist[i];
		um[plist[i]] = i;
	}
		for (int i = 0; i < m; i++) {
		string q;
		cin >> q;
		if (q[0] >= 'A') {
			cout << um[q] + 1 << "\n";
		}
		else { // num
			int num = s2i(q);
			cout << plist[num - 1] << "\n";
		}
	}
	
}