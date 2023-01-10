#include <iostream>

using namespace std;

int n, m;

int visited[9];

void dfs(int level,string s) {
	if (level > m) {
		for (int i = 0; i < m; i++) cout << s[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		//cout << i << " ";
		visited[i]++;
		s += i + '0';
		dfs(level + 1,s);
		s.erase(s.size()-1);
		visited[i]--;
	}
}


int main()
{
	cin >> n >> m;
	dfs(1,"");
}
