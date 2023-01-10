#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;

queue <int> q;

int main()
{
	FIO;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size()!=1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
}