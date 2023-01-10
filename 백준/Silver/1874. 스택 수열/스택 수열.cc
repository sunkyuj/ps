#include <iostream>
#include <algorithm>
#include <limits.h>
#include <stack>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
int arr[100001];
string ans = "";
stack <int> st;

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int x = 1;
	int i = 0;
	
	while (!st.empty()||x<=n) {
		if (st.empty()) {
			st.push(x++);
			ans += '+';
		}
		if (st.top() == arr[i]) {
			st.pop();
			ans += '-';
			i++;
		}
		else if(x<=n){
			st.push(x++);
			ans += '+';
		}
		else {
			cout << "NO";
			return 0;
		}

		
	}

	for (int i = 0; i < ans.size(); i++) cout << ans[i] << "\n";
}