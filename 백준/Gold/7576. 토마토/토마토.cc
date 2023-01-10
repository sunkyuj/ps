#include <iostream>
#include <queue>

using namespace std;

int m, n;
int arr[1001][1001];
int visited[1001][1001];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

typedef pair<int, int> yx;

bool in_range(int y, int x) {
	return y >= 0 && y < n&& x >= 0 && x < m;
}

void reset_visited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if(visited[i][j]==1) visited[i][j] = 0;
	}
}

bool is_done() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) return 0;
		}
	}
	return 1;
}

/*
2-2
3-4
4-6
5-8
...
n=>(n-1)*2 

*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> arr[i][j];
	}

	int day = 0;
	
	queue<yx> expand;

	for (int i = 0; i < n; i++) { //최초로 한번 맵 전체 다 훑어 토마토 위치 파악.
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {

				queue <yx> q;
				q.push({ i,j });
				visited[i][j] = 1;

				while (!q.empty()) {
					int y = q.front().first, x = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k], nx = x + dx[k];
						if (in_range(ny, nx) && arr[ny][nx] == 1 && !visited[ny][nx]) {
							q.push({ ny,nx });
							visited[ny][nx] = 1;
						}
						if (in_range(ny, nx) && arr[ny][nx] == 0 && !visited[ny][nx]) {
							expand.push({ ny,nx });
							visited[ny][nx] = 1;
						}
					}
				}
			}
		}
	}

	
	while (!is_done()) { //day
		
		if (!is_done() && expand.empty()) { //늘어날게 없을 때
			cout << -1;
			return 0;
		}

		queue <yx> tmp;
		while (!expand.empty()) {
			int y = expand.front().first, x = expand.front().second;
			expand.pop();
			arr[y][x] = 1;

			for (int k = 0; k < 4; k++) { //expand 안에 원소들 사방으로 검사
				int ny = y + dy[k], nx = x + dx[k];
				if (in_range(ny, nx) && arr[ny][nx] == 0 && !visited[ny][nx]) {
					tmp.push({ ny,nx });
					visited[ny][nx] = 1;
				}
			}
		}
		//expand 한 턴 끝나면 하루가 지나고
		day++;
		//tmp에 있는 내일 애들을 expand로 옮겨준다
		while (!tmp.empty()) {
			expand.push(tmp.front());
			tmp.pop();
		}

	}//day

	cout << day;


}
