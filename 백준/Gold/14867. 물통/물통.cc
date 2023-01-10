#include <iostream>
#include <queue>
#include <vector>
#include<unordered_map>

using namespace std;
int a_max, b_max, a_goal, b_goal;


queue <pair<int, int>> q;

//vector<vector<int>> memo(100001,vector<int>(100001,0)); // min 작업수

//int memo[10001][10001];

//vector<pair<int, int>> memo;

unordered_map<int, unordered_map <int, int> > memo;


pair<int, int> Mab(int a, int b) { //move a->b
	if (a + b <= b_max) {
		return { 0,a + b };
	}
	else {
		return { a - (b_max - b),b_max };
	}
}

pair<int, int> Mba(int a, int b) { //move b->a
	if (a + b <= a_max) {
		return { a + b, 0 };
	}
	else {
		return { a_max, b - (a_max - a) };
	}
}


int bfs(int a_cur , int b_cur) {
	
	memo[a_cur][b_cur]=1;
	q.push({ a_cur,b_cur });

	while (!q.empty()) {
		int a = q.front().first, b = q.front().second;
		q.pop();

		if (a == a_goal && b == b_goal) return memo[a][b]-1;

		pair <int, int> Fa = { a_max,b }, Fb = { a,b_max }, Ea = { 0,b }, Eb = { a,0 }, M_ab = Mab(a, b), M_ba = Mba(a, b);

		if (!memo[Fa.first][Fa.second]) {
			q.push(Fa);
			memo[Fa.first][Fa.second] = memo[a][b] + 1;
		}
		if (!memo[Fb.first][Fb.second]) {
			q.push(Fb);
			memo[Fb.first][Fb.second] = memo[a][b] + 1;
		}
		if (!memo[Ea.first][Ea.second]) {
			q.push(Ea);
			memo[Ea.first][Ea.second] = memo[a][b] + 1;
		}
		if (!memo[Eb.first][Eb.second]) {
			q.push(Eb);
			memo[Eb.first][Eb.second] = memo[a][b] + 1;
		}
		if (!memo[M_ab.first][M_ab.second]) { //Mab
			q.push(M_ab);
			memo[M_ab.first][M_ab.second] = memo[a][b] + 1;
		}
		if (!memo[M_ba.first][M_ba.second]) { //Mba
			q.push(M_ba);
			memo[M_ba.first][M_ba.second] = memo[a][b] + 1;
		}
	}
	return -1;
	
}


/*

(x,y)

(if !F)
1. Fx
2. Fy

(if !E)
3. Ex
4. Ey

5. Mxy (if !xE && !yF)
6, Myx (if !yE && !xF)


*/


int main()
{
	cin >> a_max >> b_max >> a_goal >> b_goal;
	int a_cur=0, b_cur=0;
	
	
	cout << bfs(a_cur,b_cur);
}
