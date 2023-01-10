#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <stack>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

vector<int> pre;
int n;

void f(int idx,int s,int e) {
	
	int cur = pre[idx];
	int lci = 0, rci = 0; //idx 0 is always root
	
	if (idx + 1 <= n - 1 && cur>pre[idx + 1]) lci = idx + 1;

	for (int i = e; i >= s; i--) {
		if (cur > pre[i]) break;
		rci = i;		
	}
	
	if (lci) f(lci, lci + 1, (rci == 0) ? e : rci-1);
	if (rci) f(rci, rci + 1, e);
	
	cout << cur << "\n";
}

int main()
{
	FIO;
	int x;
	while (cin >> x) pre.push_back(x);
	n = pre.size();

	
	f(0, 1, n - 1);
	
}