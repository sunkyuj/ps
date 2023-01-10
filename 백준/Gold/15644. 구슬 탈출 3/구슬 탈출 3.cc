#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n, m;
string arr[11];
int _Ry, _Rx, _By, _Bx, Oy, Ox;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };  //drul
string drul[4] = { "D","R","U","L" };
int ans = -1;
string ans_path;

void f(int cnt, int dir, int Ry, int Rx, int By, int Bx , string path) {

	if (ans != -1 && cnt >= ans) return;

	//bool B_blocks = false;
	bool R_goal = false;

	while (arr[Ry + dy[dir]][Rx + dx[dir]] != '#') { // move R
		if (Ry + dy[dir] == By && Rx + dx[dir] == Bx) break; // move B first
		Ry += dy[dir];
		Rx += dx[dir];
		if (Ry == Oy && Rx == Ox) {
			R_goal = true;

			Rx = -1;
			Ry = -1;
			break;
		}
	}
	while (arr[By + dy[dir]][Bx + dx[dir]] != '#') { // move B
		if (By + dy[dir] == Ry && Bx + dx[dir] == Rx) break;
		By += dy[dir];
		Bx += dx[dir];
		if (By == Oy && Bx == Ox) return; //fail
	}

	while (!R_goal && arr[Ry + dy[dir]][Rx + dx[dir]] != '#') { // move R again
		if (Ry + dy[dir] == By && Rx + dx[dir] == Bx) break;
		Ry += dy[dir];
		Rx += dx[dir];
		if (Ry == Oy && Rx == Ox) {
			R_goal = true;
			Rx = -1;
			Ry = -1;
			break;
		}
	}

	if (R_goal) {
		if (ans == -1 || ans > cnt) {
			ans = cnt;
			ans_path = path;
		}
		return;
	}

	if (cnt == 10) return;

	for (int k = 0; k < 4; k++) f(cnt + 1, k, Ry, Rx, By, Bx, path+drul[k]);


}


int main()
{
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '.' || arr[i][j] == '#') continue;
			if (arr[i][j] == 'R') {
				_Ry = i;
				_Rx = j;
			}
			else if (arr[i][j] == 'B') {
				_By = i;
				_Bx = j;
			}
			else if (arr[i][j] == 'O') {
				Oy = i;
				Ox = j;
			}
			arr[i][j] = '.';
		}
	}



	for (int k = 0; k < 4; k++) f(1, k, _Ry, _Rx, _By, _Bx, drul[k]);


	cout << ans << "\n" << ans_path;
}