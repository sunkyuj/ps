#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

int arr[9];
int visited[9];


vector <int> v;

void dfs(int level) {
	if (level == m) {
		for (int i = 0; i < m; i++) cout << v[i] << " ";
		cout << "\n";
		return;
	}

	int prev = 0;
	for (int i = 0; i < n; i++) {
		//if (visited[i]) continue;

		if ( arr[i] != prev) {

			//if (!v.empty() && v.back() > arr[i]) continue;

			prev = arr[i];
			v.push_back(arr[i]);
			visited[i] = 1;

			dfs(level + 1);

			v.pop_back();
			visited[i] = 0;
		}
	}


}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	dfs(0);



}
