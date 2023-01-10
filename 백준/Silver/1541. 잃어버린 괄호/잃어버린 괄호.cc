#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string>
#include <stack>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

string s;
int last_op_idx = 0;
int num[51];
char op[51];
stack<int> n_st;
stack<char> op_st;

int s2i(string s) {
	int jari = 1;
	int sum = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		sum += (s[i] - '0') * jari;
		jari *= 10;
	}
	return sum;
}

int cal(int i) {
	int j;
	for (j = i + 1; j < s.size() && s[j] != '+' && s[j] != '-'; j++);
	return j - 1 - i;
}


int main()
{
	FIO;
	cin >> s;
	s = "+" + s;

	bool min_mode = false;
	int sum = 0;

	for (int i = 0; i < s.size(); i++) {
		int nl = 0;
		if (s[i] == '+') {
			nl = cal(i);
			int num = s2i(s.substr(i + 1, nl));
			if (min_mode) sum -= num;
			else sum += num;
		}
		else if (s[i] == '-') {
			nl = cal(i);
			int num = s2i(s.substr(i + 1, nl));
			min_mode = true;
			sum -= num;
		}
		i += nl;
	}

	cout << sum;
}