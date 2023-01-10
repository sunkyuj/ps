#include <iostream>

using namespace std;
int N;

int cnt[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N--) {
		int n;
		cin >> n;
		cnt[n]++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (cnt[i] == 0) continue;
		for (int j = 0; j < cnt[i]; j++) cout << i << "\n";
	}
	
}
