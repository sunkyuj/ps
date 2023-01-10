#include <iostream>
#include <algorithm>
#include <limits.h>
#include <stack>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
stack <int> st;

int main()
{
	FIO;
	
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) st.pop();
		else st.push(x);
	}

	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}

	cout << sum;
}