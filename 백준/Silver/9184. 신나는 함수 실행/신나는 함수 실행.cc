#include <iostream>

using namespace std;

int a, b, c;

int memo[101][101][101]; 
/* 

memo[0][0][0]== -50 -50 -50
memo[1][1][1]== -49 -49 -49

memo[50][50][50]== 0 0 0

memo[51][51][51]== 1 1 1

memo[a+50][b+50][c+50]== a b c

memo[100][100][100]== 50 50 50

*/
int w(int a,int b,int c) {
	if (memo[a + 50][b + 50][c + 50]) return memo[a + 50][b + 50][c + 50];
	if (a <= 0 || b <= 0 || c <= 0) return memo[a + 50][b + 50][c + 50]=1;
	else if (a > 20 || b > 20 || c > 20) return memo[a + 50][b + 50][c + 50]=w(20, 20, 20);
	else if (a < b && b < c) return memo[a + 50][b + 50][c + 50]=w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else return  memo[a + 50][b + 50][c + 50]=w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main()
{
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		int x = w(a, b, c);
		printf("w(%d, %d, %d) = %d\n", a, b, c, x);
	}

}
