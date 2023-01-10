#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <stack>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

stack<char> st;
//stack<char> op;
string s;

int pri(char c) {
	if (c == '(') return 0;
	else if (c == '+' || c == '-') return 1;
	else if (c == '*' || c == '/') return 2;
}

int main()
{
	FIO;
	cin >> s;
	string ans = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') ans += s[i];
		else {
			if (s[i] == '(') st.push(s[i]);
			else if (s[i] == ')') {
				while (st.top() != '(') {
					ans += st.top();
					st.pop();
				}
				st.pop();
			}
			else { //operator
				if (st.empty()) {
					st.push(s[i]);
					continue;
				}
				int cur_op_pri = pri(s[i]);
				int st_top_pri = pri(st.top());
				while (st_top_pri >= cur_op_pri) {
					ans += st.top();
					st.pop();
					if (st.empty()) break;
					else st_top_pri = pri(st.top());
				}
				st.push(s[i]);
			}
		}
	}
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	cout << ans;
	
}