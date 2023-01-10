#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;

int main()
{
	FIO;
	cin >> n;

	int num = 1;
	int distance = 1;

	while (num < n) {
		distance++;
		int room = 6 * (distance - 1);
		while (room>0) {
			num++;
			room--;
			if (num == n) {
				break;
			}
		}
	}
	cout << distance;
}