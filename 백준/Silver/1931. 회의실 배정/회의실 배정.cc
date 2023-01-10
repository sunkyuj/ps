#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef struct T {
	int start;
	int end;
}T;

int operator<(T t1, T t2) {
	int s1 = t1.start, s2 = t2.start, e1 = t1.end, e2 = t2.end;
	if (e1 < e2) return 1;
	else if (e1 == e2 && s1 < s2) return 1;
	return 0;
}

int n;
int arr[100001][2];
T t[100001];

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		//cin >> arr[i][0] >> arr[i][1];
		cin >> t[i].start >> t[i].end;
	}
	sort(t, t + n);
	
	int cnt = 1;
	int e_time = t[0].end;
	for (int i = 1; i < n; i++) {
		if (e_time <= t[i].start) {
			e_time = t[i].end;
			cnt++;
		}
	}

	
	//for (int i = 0; i < n; i++) {
		//cout << t[i].start << " " << t[i].end << "\n";
	//}
	cout << cnt;
}
/*

1 4 
3 5 
0 6 
5 7 
3 8
5 9
6 10
8 11 
8 12
2 13
12 14 

*/