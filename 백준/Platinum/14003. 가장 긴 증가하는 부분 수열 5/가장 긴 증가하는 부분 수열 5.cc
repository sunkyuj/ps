#include <iostream>
#include <algorithm>
#include <limits.h>
#include <stack>
#define MAX 1000001

using namespace std;

int n;
int arr[MAX];
int arr_idx[MAX];
stack <int> st;
//int maxL = 0;

int path[MAX];
int lis[MAX];
int lis_idx[MAX];

int bin(int last, int key) {
	int s = 0, e = last;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (key > lis[mid]) s = mid + 1;
		else if (key < lis[mid]) e = mid - 1;
		else return mid;
	}
	return s; //못찾았을 경우 s>e가 되므로 더 큰 값인 s를 리턴한다.

}


int idx_inc(int last) {
	for (int i = 1; i <= last; i++) {
		if (lis_idx[i - 1] > lis_idx[i]) return 0;
	}
	return 1;
}


int main()
{

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr_idx[i] = i;
	}
	for (int i = 0; i < n; i++) lis[i] = INT_MIN;

	int last = 0;
	lis[0] = path[0] = arr[0];
	lis_idx[0] = 0;

	for (int i = 1; i < n; i++) {
		if (lis[last] < arr[i]) { //lis 맨 끝 값보다 arr[i]가 더 크면 arr[i]를 lis 맨 끝에 붙인다.
			lis[++last] = arr[i];
			//lis_idx[last] = i;
			arr_idx[i] = last;

			/*
			if (idx_inc(last)) { //lis의 index와 값(값은 이미 오름차순) 모두 오름차순일 때 memo 새로고침
				for (int j = 0; j <= last; j++) path[j] = lis[j];
			}
			else path[last] = arr[i];
		*/
		}
		else {
			int idx = bin(last, arr[i]);
			lis[idx] = arr[i];
			arr_idx[i] = idx;
			/*
			if (lis[idx]!=arr[i]) {
				lis[idx] = arr[i];
				lis_idx[idx] = i;
			}*/
		}

	}
	int len = last + 1;
	
	for (int i = n - 1; i >= 0; i--) {
		if (last == arr_idx[i]) {
			st.push(arr[i]);
			last--;
		}
	}

	cout << len << "\n";

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	
	/*
	for (int i = 0; i <= last; i++) {
		cout << path[i] << " ";
	}
	*/
}



/*

 A = {10, 20, 7, 10, 25, 30, 20, 50,}

 */