#include <iostream>
#define MAX 1000001

using namespace std;

//typedef long long ll;

int mod_memo[MAX] = { 0,1,1 };
int p, n, m;


int k(int m) {
	int i = 3;
	bool cur_0_prev_1 = false;
	while (1) {
		if(cur_0_prev_1) return i;
		mod_memo[i] = (mod_memo[i-1] + mod_memo[i-2])%m;
		if (mod_memo[i] == 0 && mod_memo[i - 1] == 1) cur_0_prev_1 = true;
		else i++;
	}
}

int main()
{
	// 1  2  3   4   5   6   7    8     9   10   11    12       n
	// 1  1	 2   3	 5   8   13   21   34   55   89   144      fib(n)

	// 1  1  2   3   5   8   2    10    1    0    1     1       m=11
	// 1  1  2   0   2   2   1    0     1    1    2             m=3
	// 1  1  2   3   1   0   1     1    2    
	// m=2, k(m=2)=3
	// 0 다음 1 나오면 주기


	cin >> p;
	for (int i = 1; i <= p;i++) {
		cin >> n >> m;
		//if(m==2) cout << i << " " << 3 << "\n";
		cout << i << " " << k(m) << "\n";
	}
	
}
