#include <iostream>

using namespace std;

int n,m;
int arr[100002];
int i2n_sum[100002];

void init() {
	int sum = 0;
	for (int i = n; i >= 1; i--) {
		sum += arr[i];
		i2n_sum[i] = sum;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cin >> m;
	init();

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		
		cout << i2n_sum[a] - i2n_sum[b+1] << "\n";
		
	}
}
