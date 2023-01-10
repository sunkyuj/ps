#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1000001];
//int maxL = 0;

//int memo[1000001];
int lis[1000001];

int bin(int lis_len, int key) {
	int s = 0, e = lis_len - 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (key > lis[mid]) s = mid + 1;
		else if (key < lis[mid]) e = mid - 1;
		else return mid;
	}
	return s; //못찾았을 경우 s>e가 되므로 더 큰 값인 s를 리턴한다.

}


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
		else if (lis[last] > arr[i]) {
			int idx = bin(last + 1, arr[i]);
			lis[idx] = arr[i];
		}
	}

	cout << last + 1;

}



/*

 A = {10, 20, 7, 10, 25, 30, 20, 50,}

 */