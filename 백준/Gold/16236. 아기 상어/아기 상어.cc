#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <queue>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

typedef pair<int, int> yx;

int n;
int arr[21][21];
yx baby;
int baby_size = 2;
int eat_stack = 0;
int t = 0;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

/*

아기상어(9) 처음 크기 2, 자기보다 큰애는 못먹음
1초에 한칸 이동 가능
크기가 n일때 물고기 n마리 먹으면 크기가 n+1이 됨
크기가 3일때 물고기 3마리 먹으면 크기가 4가 됨

자기보다 크기가 큰 물고기가 있는 칸은 못지나감
크기가 같은 물고기가 있는 칸은 지나갈 수 있음

*/
bool all_eat() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0 && arr[i][j] != 9) return false;
		}
	}
	return true;
}
bool in_range(int y, int x) {
	return y >= 0 && y < n&& x >= 0 && x < n;
}
yx find() {
	int min_len = 400;
	int I = -1, J = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] >= 1 && arr[i][j] < baby_size) {
				bool visited[21][21] = {};
				queue<yx> q;
				queue<int> lq;
				q.push({ i,j });
				lq.push(0);
				visited[i][j] = 1;
				while (!q.empty()) {
					int y = q.front().first, x = q.front().second;
					q.pop();
					int len = lq.front();
					lq.pop();
					if (y == baby.first && x == baby.second) {
						if (min_len > len) {
							min_len = len;
							I = i; J = j;
						}
						break;
					}
					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k], nx = x + dx[k];
						if (in_range(ny, nx) && baby_size >= arr[ny][nx]&&!visited[ny][nx]) {
							q.push({ ny,nx });
							lq.push(len + 1);
							visited[ny][nx] = 1;
						}
					}
				}
			}
		}
	}
	if (I != -1 && J != -1) {
		t += min_len;
		arr[I][J] = 0;/////////
	}
	return { I,J };
}



int main()
{
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				baby = { i,j };
				arr[i][j] = 0;
			}
		}
	}


	while (!all_eat()) {
		yx target = find();
		if (target.first==-1&&target.second==-1) {
			break;
		}
		
		//t += abs(baby.first - target.first) + abs(baby.second - target.second);
		//arr[target.first][target.second] = 0;
		

		baby = target;
		eat_stack++;
		if (eat_stack == baby_size) {
			baby_size++;
			eat_stack = 0;
		}
	}

	cout << t;

}