#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <queue>
#include <map>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int arr[101];
int visit[101];
map<int, int> stair; // 1
map<int, int> snake; // -1

int dist[101];

int n, m;

int main()
{
	FIO;
	cin >> n >> m;
	for (int i = 1; i < 101; i++) dist[i] = INT_MAX;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		stair[a] = b;
		arr[a] = 1;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		snake[a] = b;
		arr[a] = -1;
	}

	
	/*
	cur에 있다고 했을때:
		6이내에 사다리, 뱀, 100 이 있으면 동작 수행

	최소한의 이동 횟수로 최대한의 거리 가기x
	어차피 한 칸에 여러개의 사다리나 뱀은 불가능함
	즉, 모든 칸에 번씩만 밟게 상황을 만들 수 있고,
	만일 i+1 과 i+6 사이에 전부 빈칸이면 i+6으로 간다

	그러면 i+1 부터 i+6까지 전부 뱀이나 사다리가 있으면..?
	우선순위 큐를 이용해서 제일 멀리 갈수있는 애부터 해볼까..
	*/

	

	// max movement : 6 

	
	//int cur = 1;
	visit[1] = 1;
	dist[1] = 0;
	priority_queue<pair<int, int>> pq; //max heap, {길이,층}, 길이는 작은게 좋으니 - 붙여준다
	pq.push({ 0,1 });

	while (!pq.empty()) {
		int len = pq.top().first, floor = pq.top().second; // len < 0
		pq.pop();
		
		if (dist[floor] < -len) continue;
		dist[floor] = -len;

		for (int i = 1; i <= 6; i++) {
			if (visit[floor + i]||floor+i>100) continue;

			if (arr[floor+i] == 1) {//stair +
				pq.push({ len - 1,stair[floor + i] });
				visit[floor + i] = 1;
				visit[stair[floor + i]] = 1;
			}
			else if (arr[floor + i] == -1) {//snake -
				pq.push({ len - 1,snake[floor + i] });
				visit[floor + i] = 1;
				visit[snake[floor + i]] = 1;
			}
			else {// 0
				pq.push({ len - 1,floor + i });
				visit[floor + i] = 1;
			}
		}
	}
	cout << dist[100];

	//cout << f(100);

}