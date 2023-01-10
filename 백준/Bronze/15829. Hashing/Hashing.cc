#include <iostream>
#include <algorithm>
#include <limits.h>
//#include <cmath>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

const int M = 1234567891;

int n;
string s;


int main()
{
	FIO;
	cin >> n >> s;
	long long sum = 0;
	long long R = 1;
	for (int i = 0; i < n; i++) {
		long long a = ((s[i] - 'a')%M + 1)%M;
		sum += (a * R)%M;
		R = (R * 31) % M;
		
		
	}
	cout << sum;
}