#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <stack>



#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

string s;
string bomb;

int main()
{
	FIO;

	cin >> s >> bomb;
	int bl = bomb.size();
	//char bomb_last = bomb.back();
	vector<char> st;
	for (int i = 0; i < s.size(); i++) {
		st.push_back(s[i]);
		if (st.size() >= bl && st.back() == bomb.back()) {
			bool same = true;
			string tmp = "";
			for (int j = bl - 1; j >= 0; j--) {
				if (bomb[j] == st.back()) {
					tmp.push_back(bomb[j]);
					st.pop_back();
				}
				else {
					same = false;
					break;
				}
			}

			if (!same) {
				for (int j = tmp.size() - 1; j >= 0; j--) st.push_back(tmp[j]);
			}
		}
	}

	if (st.empty()) cout << "FRULA";
	else for (int i = 0; i < st.size(); i++) cout << st[i];
	
}