#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n, r;
string mm[101][101];

string sum(string l, string r) {
	string s;
	int jari = 0;
	int llen = l.size(), rlen = r.size();
	
	int upper = 0;
	int lp = llen - 1, rp = rlen - 1;
	while (!(lp<0&&rp<0)||upper==1) {
		int lc = (lp < 0) ? 0 : l[lp] - '0';
		int rc = (rp < 0) ? 0 : r[rp] - '0';
		int hap = lc + rc + upper;

		if (hap >= 10) {
			upper = 1;
			hap %= 10;
		}
		else upper = 0;

		s.push_back(hap + '0');
		lp--; rp--; jari++;
	}

	reverse(s.begin(), s.end());
	return s;
}

int main()
{
	FIO;
	cin >> n >> r;
	mm[1][0] = mm[1][1] = "1";
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) mm[i][j] = "1";
			else mm[i][j] = sum(mm[i - 1][j - 1], mm[i - 1][j]);
		}
	}
	cout << mm[n][r];

}