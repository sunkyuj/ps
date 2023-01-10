#include <iostream>
#include <algorithm>


using namespace std;

int n;
int arr[40001];
int lis[40001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int last = 0;
	lis[0] = arr[0];
	
	for (int i = 1; i < n; i++) {
		if (lis[last] < arr[i]) {
			lis[++last] = arr[i];
		}
		else {
			auto it = lower_bound(lis, lis + last, arr[i]);
			int idx = it - begin(lis);
			lis[idx] = arr[i];
		}
		
	}
	
	cout << last + 1;

}


/*

n=6

1 2 3 4 5 6
4 2 6 3 1 5


*/
