#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n;

//int M[100001][3];
//int m[100001][3];
int p0, p1, p2;
int mp0, mp1, mp2;


int main()
{
	FIO;
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;

	p0 = a;
	p1 = b;
	p2 = c;

	mp0 = a;
	mp1 = b;
	mp2 = c;

	for (int i = 1; i < n; i++) {
		int tmp0, tmp1, tmp2;
		cin >> a >> b >> c;
		tmp0 = a + max(p0, p1);
		tmp1 = b + max(max(p0, p1), p2);
		tmp2 = c + max(p1, p2);
		p0 = tmp0;
		p1 = tmp1;
		p2 = tmp2;

		tmp0 = a + min(mp0, mp1);
		tmp1 = b + min(min(mp0, mp1), mp2);
		tmp2 = c + min(mp1, mp2);
		mp0 = tmp0;
		mp1 = tmp1;
		mp2 = tmp2;
	}
	cout << max(max(p0, p1), p2) << " ";
	cout << min(min(mp0, mp1), mp2);

}