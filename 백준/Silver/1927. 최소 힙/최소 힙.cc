#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;
priority_queue <int,vector<int>,greater<int>> pq;
int n;

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				cout<<pq.top()<<"\n";
				pq.pop();
			}
		}
		else pq.push(x);
		
	}
}