#include <iostream>

using namespace std;

int n, m;

int arr[9] = { 0,1,2,3,4,5,6,7,8 };
int visited[9];

void dfs(string s) {
	if (s.size() == m) {
		for (int i = 0; i < m; i++) cout << s[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		s += i + '0';
		dfs(s);
		s.erase(s.size() - 1);
		
	}


}

int main()
{
	cin >> n >> m;
	dfs("");

}
