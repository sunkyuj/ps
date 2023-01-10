#include <iostream>
#include <algorithm>
#include <limits.h>
#include <unordered_map>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n, m;
unordered_map<string, string> um;

int main()
{
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string site,pw;
		cin >> site >> pw;
		um[site] = pw;
	}
	for (int i = 0; i < m; i++) {
		string site;
		cin >> site;
		cout << um[site]<<"\n";
	}
}