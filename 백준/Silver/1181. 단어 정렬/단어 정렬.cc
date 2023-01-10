#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
string s;
priority_queue <string,vector<string>,greater<string>> pq[51];

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		pq[s.size()].push(s);
	}
	for (int i = 1; i < 51; i++) {
		string prev="";
		while (!pq[i].empty()) {
			if(prev!= pq[i].top()) cout << pq[i].top() << "\n";
			prev = pq[i].top();
			pq[i].pop();
		}
	}
	
}
