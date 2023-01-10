#include <iostream>

using namespace std;

int a, b, v; // 1<= b < a <= v <= 1,000,000,000

int main()
{
	cin >> a >> b >> v;

	int day = 0;
	int bound = v - a;
	day++;
	int len_per_day = a - b;
	
	day += bound / len_per_day;
	if (bound % len_per_day) day++;



	
	cout << day;
	
	/*
	
	v-a 이것보단 무조건 작음 --> +1
	a-b: 하루동안 가는 거리
	
	*/
}
