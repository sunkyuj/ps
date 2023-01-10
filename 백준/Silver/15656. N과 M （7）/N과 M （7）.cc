#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;

int n, m;

int arr[9];
int visited[9];

vector <int> v;

void dfs() {
	if (v.size() == m) {
		for (int i = 0; i < m; i++) cout << v[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		//if (visited[i]) continue;

		//if (v.empty() || v.back() < arr[i]) {
			v.push_back(arr[i]);
			visited[i]++;

			dfs();

			v.pop_back();
			visited[i]--;
		//}
	}


}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	dfs();

}
