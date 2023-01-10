#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int from, to;
int visited[10000] = {0};

/*
string f() {
	queue<pair<int, string>> q;
	
	q.push({ from,"" });
	visited[from] = 1;

	while (!q.empty()) {
		int n = q.front().first;
		string s = q.front().second;
		q.pop();

		if (n == to) return s;

		if (!visited[n * 2 % 10000]) {
			q.push({ n * 2 % 10000,s + "D" });
			visited[n * 2 % 10000] = 1;
		}
		if (!visited[n == 0 ? 9999 : n - 1]) {
			q.push({ n == 0 ? 9999 : n - 1, s + "S" });
			visited[n == 0 ? 9999 : n - 1] = 1;
		}
		if (!visited[n % 1000 * 10 + n / 1000]) {
			q.push({ n % 1000 * 10 + n / 1000,s + "L" });
			visited[n % 1000 * 10 + n / 1000] = 1;
		}
		if (!visited[(n % 10) * 1000 + n / 10]) {
			q.push({ (n % 10) * 1000 + n / 10,s + "R" });
			visited[(n % 10) * 1000 + n / 10] = 1;
		}
	}
}
*/
int main()
{
	FIO;
	int T;
	cin >> T;
	while (T--) {
		cin >> from >> to;



		queue<pair<int, string>> q;

		q.push({ from,"" });
		visited[from] = 1;

		while (!q.empty()) {
			int n = q.front().first;
			string s = q.front().second;
			q.pop();

			if (n == to) {
				cout << s << "\n";
				break;
			}

			if (!visited[n * 2 % 10000]) {
				q.push({ n * 2 % 10000,s + "D" });
				visited[n * 2 % 10000] = 1;
			}
			if (!visited[n == 0 ? 9999 : n - 1]) {
				q.push({ n == 0 ? 9999 : n - 1, s + "S" });
				visited[n == 0 ? 9999 : n - 1] = 1;
			}
			if (!visited[n % 1000 * 10 + n / 1000]) {
				q.push({ n % 1000 * 10 + n / 1000,s + "L" });
				visited[n % 1000 * 10 + n / 1000] = 1;
			}
			if (!visited[(n % 10) * 1000 + n / 10]) {
				q.push({ (n % 10) * 1000 + n / 10,s + "R" });
				visited[(n % 10) * 1000 + n / 10] = 1;
			}
		}

		for (int i = 0; i < 10000; i++) visited[i] = 0;
	}

}
/*

int s2i(string s) {
	int sum = 0;
	int jari = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		sum += (s[i] - '0') * jari;
		jari *= 10;
	}
	return sum;
}
string i2s(int n) {
	string s="0000";

	for (int i = 3; i >= 0; i--) {
		s[i] += n % 10;
		n /= 10;
	}
	return s;
}
*/