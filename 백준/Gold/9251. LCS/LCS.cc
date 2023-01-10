#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

string s1, s2;
int lcs[1001][1001];

int main()
{
	FIO;
	cin >> s1 >> s2;


	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) 
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else 
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}

	cout << lcs[s1.size()][s2.size()];

}