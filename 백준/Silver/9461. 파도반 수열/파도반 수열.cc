#include <iostream>
#include <algorithm>
#include <limits.h>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n;
long long memo[101] = { 0,1,1,1,2,2};
//1,1,1,2(1+1),2(1+1),3(2+1),4(3+1),5(4+1),7(5+2),9(7+2),12(9+3),16(12+4),21(16+5)
//1 2 3 4      5      6*     7      8      9      10     11      12       13

int main()
{
	FIO;
	int T;
	cin >> T;

	for (int i = 6; i <= 100; i++) {
		memo[i] = memo[i - 1] + memo[i - 5];
	}
	//for (int i = 1; i <= 100; i++) {
	//	cout <<i<<" : "<< memo[i] << "\n";
	//}

	while (T--) {
		cin >> n;
		cout << memo[n] << "\n";
	}

}