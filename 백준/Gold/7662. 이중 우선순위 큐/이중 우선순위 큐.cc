#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <map>
#include <set>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int k, n;
string cmd;

int main()
{
	FIO;

	int T;
	cin >> T;
	while (T--) {
		multiset <int> ms;
		multiset <int>::iterator it;
		cin >> k;
		while (k--) {
			cin >> cmd;
			if (cmd == "I") {
				cin >> n;
				ms.insert(n);
			}
			else if (cmd == "D") {
				cin >> n;
				if (ms.empty()) continue;
				if (n == 1) { //del max
					ms.erase(--ms.end());
				}
				else if (n == -1) { //del min
					ms.erase(ms.begin());
				}
			}
			//for (it = ms.begin(); it != ms.end(); it++) cout << *it << " ";
			//cout << "\n";
		}
		
		if (ms.empty()) cout << "EMPTY\n";
		else cout << *(--ms.end()) << " " << *ms.begin() << "\n";
		
	}
}