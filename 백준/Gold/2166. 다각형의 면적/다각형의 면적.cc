#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <cmath>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n;
long long x[10001];
long long y[10001];


int main()
{
	//FIO;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	long long sum = 0;
	for (int i = 1; i < n; i++) {
		sum += (x[i - 1] + x[i]) * (y[i - 1] - y[i]);
	}
	sum += (x[n - 1] + x[0]) * (y[n - 1] - y[0]);
	sum = llabs(sum);
	printf("%.1lf", sum/2.0);

}