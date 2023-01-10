#include <iostream>
#include <algorithm>
#include <limits.h>
//#include <xutility>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
long long memo[10001];


int is666(long long x) {
	
	string s;
	while (x) {
		s.push_back(x % 10 + '0');
		x /= 10;
	}
	reverse(s.begin(), s.end());
	
	int cnt = 0;
	for (int i = 0; i<s.size(); i++) {
		if (s[i] == '6') cnt++;
		else cnt = 0;

		if (cnt >= 3) return 1;
	}
	return 0;
}

int main()
{
	FIO;
	cin >> n;
	
	long long x = 666;
	int idx = 1;
	while (!memo[n]) {
		if (is666(x)) memo[idx++] = x;
		x++;
	}
	cout << memo[n];

}
/*

666 1666 2666 3666 4666 5666 6666 7666 8666 9666 
10666 11666 12666 13666 14666 15666 16661 16662 16663 16664 16665 16666

*/