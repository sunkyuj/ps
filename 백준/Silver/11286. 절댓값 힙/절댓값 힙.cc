#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <cmath>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef struct NUM {
	int n;
	int op;
}NUM;

bool operator<(NUM x1,NUM x2) {
	if (x1.n == x2.n) return x1.op < x2.op;
	return x1.n < x2.n;

}
bool operator>(NUM x1, NUM x2) {
	if (x1.n == x2.n) return x1.op > x2.op;
	return x1.n > x2.n;
}
bool operator==(NUM x1, NUM x2) {
	return x1.n == x2.n && x1.op == x2.op;
}

bool operator<=(NUM x1, NUM x2) {
	return x1 < x2 || x1 == x2;

}
bool operator>=(NUM x1, NUM x2) {
	return x1 > x2 || x1 == x2;
}

int n;
priority_queue <NUM,vector<NUM>,greater<NUM>> pq;

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			//cout << "->";
			if (pq.empty()) cout << "0\n";
			else {
				cout <<pq.top().op*pq.top().n << "\n";
				pq.pop();
			}
		}
		else {
			pq.push({ abs(x),x / abs(x) });
		}
	}
}