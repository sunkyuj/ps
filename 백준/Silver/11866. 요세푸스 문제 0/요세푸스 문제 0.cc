#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n, k;
vector <int> v;
vector <int> yo;

int main()
{
	FIO;
	cin >> n >> k;
	for (int i = 0; i < n; i++) v.push_back(i + 1);
	int idx = 0;
	while (!v.empty()) {
		idx = (idx + k - 1) % v.size();
		yo.push_back(v[idx]);
		v.erase(v.begin()+idx);
	}
	cout << "<";
	for (int i = 0; i < yo.size(); i++) {
		cout << yo[i];
		if (i != yo.size() - 1) cout << ", ";
	}
	cout << ">";

}