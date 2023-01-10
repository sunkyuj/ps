#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n, m;
int tn;
int truth[51];
vector<int> party[51];
int true_party[51];


int main()
{
	FIO;
	cin >> n >> m;
	cin >> tn;
	for (int i = 0; i < tn; i++) {
		int a;
		cin >> a;
		truth[a] = 1;
	}

	for (int i = 0; i < m; i++) {
		int join;
		cin >> join;
		for (int j = 0; j < join; j++) {
			int p;
			cin >> p;
			party[i].push_back(p);
		}
	}


	for (int i = 0; i < m; i++) {
		for (int p = 0; p < m; p++) {
			for (auto& x : party[p]) {
				if (truth[x] == 1) {
					true_party[p] = 1;
					for (auto& k : party[p]) 
						truth[k] = 1;
					continue;
				}
			}
		}
	}
	int tcnt = 0;
	for (int i = 0; i < m; i++) if (!true_party[i]) tcnt++;
	cout << tcnt;
	
}