#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <stack>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n;

int arr[91][2]; //65~90

stack<char> pre,in,post;

void preorder(char cur) {
	if (cur == '.') return;
	cout << cur;
	preorder(arr[cur][0]);
	preorder(arr[cur][1]);
}
void inorder(char cur) {
	if (cur == '.') return;
	inorder(arr[cur][0]);
	cout << cur;
	inorder(arr[cur][1]);
}
void postorder(char cur) {
	if (cur == '.') return;
	postorder(arr[cur][0]);
	postorder(arr[cur][1]);
	cout << cur;
}

int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char par, left, right;
		cin >> par >> left >> right;
		arr[par][0] = left;
		arr[par][1] = right;
	}
	preorder('A'); cout << "\n";
	inorder('A'); cout << "\n";
	postorder('A'); cout << "\n";



}