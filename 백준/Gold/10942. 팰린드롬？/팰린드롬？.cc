#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n,m;
int arr[2001];
//int rra[2001];

int memo[2001][2001];
/*
int f(int s, int e) {
	while (s < e) {
		if (arr[s] != arr[e]) return 0;
		s++;
		e--;	
	}
	return 1;
}*/

void odd(int mid) {
	int l = mid, r = mid;
	while (l >= 1 && r <= n) {
		
		if (arr[l] == arr[r]) memo[l][r] = 1;
		else break;

		l--;
		r++;
	}
}
void even(int mid) {
	int l = mid, r = mid+1;
	while (l >= 1 && r <= n) {

		if (arr[l] == arr[r]) memo[l][r] = 1;
		else break;

		l--;
		r++;
	}
}

int main()
{
	FIO;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		//rra[n - i + 1] = arr[i];
	}

	for (int i = 1; i <= n; i++) { //2000 
		/*
		for (int j = i; j <= n; j++) { //1000 <- 만약 이게 중앙선이라면? j <= (i+n)/2 까지만 가면 됨
			memo[i][j] = f(i, j); //1000
		}
		*/
		odd(i);
		even(i);
	}
	cin >> m;
	
	for (int i = 0; i < m; i++) { 
		int s, e;
		cin >> s >> e;
		cout << memo[s][e] << "\n";
	}

}