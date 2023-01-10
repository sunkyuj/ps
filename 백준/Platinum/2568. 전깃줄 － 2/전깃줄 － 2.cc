#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
//int A[500001];
int p[100001]; //p[i] 는 v[i] 가 몇번째 인덱스에 있는지 알려줌

vector<pair<int,int>> v; //first: a // second: b
vector<int> cut;
vector<int> LIS;
//int inc_idx[100001];

int bin(int s, int e, int A) {
	while (s <= e) {
		int mid = (s + e) / 2;
		if (LIS[mid] < A) s = mid + 1;
		else e = mid - 1;
	}
	return s;
}

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	LIS.push_back(v[0].second);
	p[0] = 0;
	int last = 0;

	for (int i = 1; i < v.size(); i++) {
		if (LIS[last] < v[i].second) {
			LIS.push_back(v[i].second);
			p[i] = ++last;
		}
		else {
			int idx = bin(0, last, v[i].second);
			LIS[idx] = v[i].second;
			p[i] = idx;
		}
	}

	cout << n - (last + 1) << "\n";

	/*
	for (int i = 0; i <= last; i++) {
		cout << LIS[i] << " ";
	}cout << "\n";

	for (int i = 0; i < n; i++) {
		cout << p[i] << " ";
	}cout << "\n";
	*/
	for (int i = n - 1; i >= 0; i--) {
		if (p[i] == last) {
			last--;
			continue;
		}
		cut.push_back(v[i].first);
	}
	for (int i = cut.size() - 1; i >= 0; i--)
		cout << cut[i] << '\n';


	/*
	int l = 0;
	for (int i = 1; i <= 500000; i++) {
		if (A[i]) {
			int idx = 0;
			if (l == 0) {
				LIS[idx] = A[i];
				inc_idx[idx] = i;
				l++;
			}
			else {
				if (LIS[l - 1] < A[i]) {
					idx = l;
					LIS[idx] = A[i];
					inc_idx[idx] = i;
					l++;
				}
				else {
					idx = bin(0, l - 1, A[i]);
					LIS[idx] = A[i];
					if (l == 1) inc_idx[idx] = i;
					else {
						if (idx == l - 1 && inc_idx[idx - 1] < i) { //맨 오른쪽
							inc_idx[idx] = i;
						}
						else if (idx == 0 && inc_idx[idx + 1] > i) { // 맨 왼쪽
							inc_idx[idx] = i;
						}
						else {
							if (inc_idx[idx - 1] < i && i < inc_idx[idx + 1]) inc_idx[idx] = i;
						}
					}
				}
			}

		}
	}

	//cout << n - l << "\n";
	int p = 0;
	for (int i = 1; i <= 500000; i++) {
		if (!A[i]) continue;
		if (i != inc_idx[p]) cout << i << "\n";
		else p++;
	}*/


}