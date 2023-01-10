#include <iostream>
#define MAX 10000000 
#define MOD 1000000 
using namespace std;

// 0  1  2  3  4  5  6  7  8  9 10 ...
// 0  1  1  2  3  5  8 13 21 34 55 ...

int mod_memo[MAX] = {0,1}; 
//int arr[MAX] = { 0,1 };
long long n;

int k(int m) {

	int i = 2;
	bool cur_0_prev_1 = false;

	while (1) {
		if (cur_0_prev_1) return i;
		mod_memo[i] = (mod_memo[i - 1] + mod_memo[i - 2]) % m;
		if (mod_memo[i] == 0 && mod_memo[i - 1] == 1) cur_0_prev_1 = true;
		else i++;
	}
}
//1000000000000000000
int main()
{
	int cycle = k(MOD);
	cin >> n;
	//cout << cycle << "\n";
	
	cout << mod_memo[n%cycle];

}
