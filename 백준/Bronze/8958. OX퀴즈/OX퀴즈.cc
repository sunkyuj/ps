#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int sum=0;
		cin >> s;
		int bonus = 0;
		for (int j = 0; j < s.size(); j++) {
			
			if (s[j] == 'O') {
				sum += ++bonus;
			}
			else {
				bonus = 0;
			}
			
		}
		cout << sum << "\n";
	}
}