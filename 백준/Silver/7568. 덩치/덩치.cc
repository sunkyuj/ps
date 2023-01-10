#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
int w[51], h[51];
int grade[51];

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> h[i];
		grade[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (w[i] < w[j] && h[i] < h[j]) grade[i]++;
		}
	}
	for (int i = 0; i < n; i++) cout << grade[i] << " ";
}