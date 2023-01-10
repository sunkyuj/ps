#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <queue>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

void U(int cnt, vector<vector<int>> v);
void D(int cnt, vector<vector<int>> v);
void L(int cnt, vector<vector<int>> v);
void R(int cnt, vector<vector<int>> v);

int n;
int max_n = 0;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

void print(vector<vector<int>> v) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << v[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}


int main()
{
	FIO;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> v[i][j];
	}

	
	U(1, v);
	D(1, v);
	L(1, v);
	R(1, v);
	

	cout << max_n;


	// 한 번의 이동에서 이미 합쳐진 블록은 또 합쳐질 수 없기 때문이다.
	// 똑같은 수가 세 개가 있는 경우에는 이동하려고 하는 쪽의 칸이 먼저 합쳐진다
	// 즉 위로 이동할 때는 y==0은 생략, y==1 이동, y==2 이동 ... y==n-1 이동
}
void U(int cnt, vector<vector<int>> v) {

	queue<int> q;
	vector<vector<int>> new_v(n, vector<int>(n, 0));

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			if (v[i][j] != 0) q.push(v[i][j]);
		}

		int i = 0;
		while (!q.empty()) {
			int fr = q.front();
			q.pop();
			new_v[i][j] = fr;
			if (!q.empty() && q.front() == fr) {
				new_v[i][j] *= 2;
				q.pop();
			}
			if (new_v[i][j] > max_n) max_n = new_v[i][j];
			i++;
		}
	}
	//print(new_v);

	if (cnt < 5) { // go next
		U(cnt + 1, new_v);
		D(cnt + 1, new_v);
		L(cnt + 1, new_v);
		R(cnt + 1, new_v);
	}
}

void D(int cnt, vector<vector<int>> v) {

	queue<int> q;
	vector<vector<int>> new_v(n, vector<int>(n, 0));

	for (int j = 0; j < n; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (v[i][j] != 0) q.push(v[i][j]);
		}

		int i = n - 1;
		while (!q.empty()) {
			int fr = q.front();
			q.pop();
			new_v[i][j] = fr;
			if (!q.empty() && q.front() == fr) {
				new_v[i][j] *= 2;
				q.pop();
			}
			if (new_v[i][j] > max_n) max_n = new_v[i][j];
			i--;
		}
	}
	//print(new_v);

	if (cnt < 5) { // go next
		U(cnt + 1, new_v);
		D(cnt + 1, new_v);
		L(cnt + 1, new_v);
		R(cnt + 1, new_v);
	}
}
void L(int cnt, vector<vector<int>> v) {

	queue<int> q;
	vector<vector<int>> new_v(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] != 0) q.push(v[i][j]);
		}

		int j = 0;
		while (!q.empty()) {
			int fr = q.front();
			q.pop();
			new_v[i][j] = fr;
			if (!q.empty() && q.front() == fr) {
				new_v[i][j] *= 2;
				q.pop();
			}
			if (new_v[i][j] > max_n) max_n = new_v[i][j];
			j++;
		}
	}

	//print(new_v);
	if (cnt < 5) { // go next
		U(cnt + 1, new_v);
		D(cnt + 1, new_v);
		L(cnt + 1, new_v);
		R(cnt + 1, new_v);
	}
}
void R(int cnt, vector<vector<int>> v) {

	queue<int> q;
	vector<vector<int>> new_v(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (v[i][j] != 0) q.push(v[i][j]);
		}

		int j = n - 1;
		while (!q.empty()) {
			int fr = q.front();
			q.pop();
			new_v[i][j] = fr;
			if (!q.empty() && q.front() == fr) {
				new_v[i][j] *= 2;
				q.pop();
			}
			if (new_v[i][j] > max_n) max_n = new_v[i][j];
			j--;
		}
	}
	//print(new_v);
	if (cnt < 5) { // go next
		U(cnt + 1, new_v);
		D(cnt + 1, new_v);
		L(cnt + 1, new_v);
		R(cnt + 1, new_v);
	}
}