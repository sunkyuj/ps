#include <iostream>
#include <algorithm>
#include <limits.h>
#include <string>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
int m;
string s;
int mark[1000001];

void marking() {
	for (int i = 0; i < m; i++) {
		if (s[i] == 'I') {
			int cnt = 0;
			char need = 'O';
			int j;
			for (j = i + 1; j < m; j++) {
				if (s[j] == need) {
					if (need == 'I') {
						cnt++;
						need = 'O';
					}
					else need = 'I';
				}
				else break;
			}
			mark[i] = cnt;
			i = j - 1;
		}
	}
}


int main()
{
	FIO;
	cin >> n >> m >> s;
	marking();
	int sum = 0;
	for (int i = 0; i < m; i++) {
		if (mark[i] >= n) {
			sum += mark[i] - n + 1;
			i += mark[i] * 2;
		}
	}
	cout << sum;
}