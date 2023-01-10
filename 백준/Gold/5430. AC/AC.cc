#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <string>
#include <deque>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

deque <string> make_dq(string input) {
	deque <string> dq;
	input.erase(--input.end());

	for (int i = 0; i < input.size(); i++) {
		if (input[i] != ','&& input[i] != '['&& input[i] != ']') {
			int j;
			for (j = i; j<input.size()&&input[j] != ','; j++);
			dq.push_back(input.substr(i,j-i));
			i = j;
		}
	}
	return dq;
}
/*
1
RRD
6
[1,1,2,3,5,8]
[1,2,3,5,8]]
*/
int main()
{
	FIO;
	int T;
	cin >> T;
	while (T--) {
		string cmd;
		cin >> cmd;
		int n;
		cin >> n;
		string input;
		cin >> input;
		
		deque<string> dq=make_dq(input);
		
		
		bool r = false;
		bool error = false;

		for (int i = 0; i < cmd.size(); i++) {
			if (cmd[i] == 'R') {
				r = !r;
			}
			else if (cmd[i] == 'D') {
				if (dq.empty()) {
					cout << "error\n";
					error = true;
					break;
				}

				if (r) { //reversed
					dq.pop_back();
				}
				else {
					dq.pop_front();
				}

			}
		}

		if (error) continue;

		if (dq.empty()) cout << "[]\n";
		else {

			cout << "[";
			if (r) {
				while (!dq.empty()) {
					if (dq.size() == 1) cout << dq.back();
					else cout << dq.back() << ",";
					dq.pop_back();
				}
			}
			else {
				while (!dq.empty()) {
					if (dq.size() == 1) cout << dq.front();
					else cout << dq.front() << ",";
					dq.pop_front();
				}
			}

			cout << "]\n";
		}



	}
}