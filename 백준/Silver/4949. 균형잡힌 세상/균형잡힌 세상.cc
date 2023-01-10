#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string>
#include <stack>
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int match(char open, char close) {
	if (open == '(' && close == ')') return 1;
	if (open == '{' && close == '}') return 1;
	if (open == '[' && close == ']') return 1;
	return 0;
}

int main()
{
	FIO;
	while (1) {
		string s;
		getline(cin, s);
		if (s == ".") break;

		bool balanced = true;
		stack <char> st;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				st.push(s[i]);
			}
			else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
				if (!st.empty() && match(st.top(), s[i])) {
					st.pop();
				}
				else {
					balanced = false;
					break;
				}
			}
		}
		if (!st.empty()) balanced = false;

		if (balanced) cout << "yes\n";
		else cout << "no\n";
	}
}