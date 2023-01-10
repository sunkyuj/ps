#include <iostream>
#include <algorithm>
#include <limits.h>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int M,n;
bool has[21];
string s;

int main()
{
	FIO;
	cin >> M;
	while (M--) {
		
		cin >> s;
		if (s == "add") {
			cin >> n;
			has[n] = 1;
		}
		else if (s == "remove") {
			cin >> n;
			has[n] = 0;
		}
		else if (s == "check") {
			cin >> n;
			cout << has[n] << "\n";
		}
		else if (s == "toggle") {
			cin >> n;
			has[n] = !has[n];
		}
		else if (s == "all") {
			for (int i = 1; i <= 20; i++) has[i] = 1;
		}
		else if (s == "empty") {
			for (int i = 1; i <= 20; i++) has[i] = 0;
		}
	}

}