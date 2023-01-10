#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int r, c, t;
vector<vector<int>> arr(51,vector<int>(51));
int up, down;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

bool in_range(int y, int x) {
	return y >= 0 && y < r&& x >= 0 && x < c;
}

vector<vector<int>> expand() {
	vector<vector<int>> tmp(51, vector<int>(51));


	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 0 || arr[i][j] == -1) continue;
			
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k], nx = j + dx[k];
				if (!in_range(ny, nx) || arr[ny][nx] == -1) continue;

				cnt++;
				tmp[ny][nx] += arr[i][j] / 5;
			}
			tmp[i][j] += arr[i][j] - (arr[i][j] / 5) * cnt;
		}
	}

	tmp[up][0] = tmp[down][0] = -1;

	return tmp;
}

vector<vector<int>> filter() {
	vector<vector<int>> tmp(51, vector<int>(51));

	tmp[1][0] = arr[0][0];
	tmp[0][c-2] = arr[0][c-1];
	//
	tmp[up-1][c-1] = arr[up][c-1];

	for (int i = 1; i < up; i++) {
		tmp[i + 1][0] = arr[i][0];
		tmp[i - 1][c-1] = arr[i][c-1];
	}

	for (int j = 1; j < c - 1; j++) {
		tmp[0][j - 1] = arr[0][j];
		tmp[up][j + 1] = arr[up][j];
	}


	//
	tmp[down+1][c - 1] = arr[down][c - 1];
	tmp[r - 1][c - 2] = arr[r - 1][c - 1];
	tmp[r-2][0] = arr[r-1][0];

	for (int i = down+1; i < r-1; i++) {
		tmp[i - 1][0] = arr[i][0];
		tmp[i + 1][c - 1] = arr[i][c - 1];
	}

	for (int j = 1; j < c - 1; j++) {
		tmp[down][j + 1] = arr[down][j];
		tmp[r - 1][j - 1] = arr[r - 1][j];
	}

	for (int i = 1; i < r-1; i++) {
		if (i == up || i == down) continue;

		for (int j = 1; j < c - 1; j++) {
			tmp[i][j] = arr[i][j];
		}
	}

	tmp[up][0] = tmp[down][0] = -1;
	return tmp;
}


int main()
{
	FIO;
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) cin >> arr[i][j];
	}
	for (int i = 0; i < r; i++) { //set filter
		if (arr[i][0] == -1) {
			up = i;
			down = i + 1;
			break;
		}
	}

	while (t--) {
		//1.미세먼지가 확산된다. 확산은 미세먼지가 있는 모든 칸에서 동시에 일어난다.
		arr = expand();


		
		 
		//2.공기청정기가 작동한다.
		arr = filter();


		

	}

	int sum = 2;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) sum += arr[i][j];
	}
	cout << sum;

}