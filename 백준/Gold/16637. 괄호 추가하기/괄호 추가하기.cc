#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

typedef long long ll;

int n;
string s;

ll M = INT_MIN;

ll cal(ll x, char op, ll y) {
	if (op == '+') return x + y;
	else if (op == '-') return x - y;
	else return x * y;
}
void dfs(int idx, ll sum, int prev_op_idx) {

	if (idx >= s.size()) {
		if (M < sum)M = sum;
		return;
	}

	char prev_op = (prev_op_idx == -1) ? '+' : s[prev_op_idx];

	//괄호 ㄱㄱ
	if (idx + 2 < s.size()) {
		ll brac = cal(s[idx] - '0', s[idx + 1], s[idx + 2] - '0');
		dfs(idx + 4, cal(sum, prev_op, brac), idx + 3);
	}

	//그냥 넘어가기
	dfs(idx + 2, cal(sum, prev_op, s[idx] - '0'), idx + 1);
}


int main()
{
	FIO;
	cin >> n >> s;

	dfs(0, 0, -1);
	cout << M;
}

