#include <iostream>

using namespace std;

string board[9];

string ans[9];


void print_b() {
	cout << "\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) cout << board[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

int is_dup(int i, int j, char k) {

	for (int garo = 0; garo < 9; garo++) if (board[i][garo] == k) return 1;
	for (int sero = 0; sero < 9; sero++) if (board[sero][j] == k) return 1;

	int rstart, rend, cstart, cend;
	if (i <= 2) {
		rstart = 0;
		rend = 2;
	}
	else if (i <= 5) {
		rstart = 3;
		rend = 5;
	}
	else {
		rstart = 6;
		rend = 8;
	}

	if (j <= 2) {
		cstart = 0;
		cend = 2;
	}
	else if (j <= 5) {
		cstart = 3;
		cend = 5;
	}
	else {
		cstart = 6;
		cend = 8;
	}
	for (int r = rstart; r <= rend; r++) {
		for (int c = cstart; c <= cend; c++) {
			if (board[r][c] == k) return 1;
		}
	}
	return 0;
}


int dfs() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == '0') {
				int k;
				for (k = 1; k <= 9; k++) {
					if (is_dup(i, j, k+'0')) continue;
					board[i][j] = k+'0';
					//print_b();
					if (dfs()) return 1;
					//dfs();
					board[i][j] = '0';
				}
				if (k == 10) return 0;
			}
		}
	}
	return 1;
	/*
	if (board[8][8] <= ans[8][8]) {
		for (int i = 0; i < 9; i++) ans[i] = board[i];
	}*/
}

int main()
{
	//for (int i = 0; i < 9; i++) ans[i] = "999999999";

	for (int i = 0; i < 9; i++) cin >> board[i];
	
	dfs();

	for (int i = 0; i < 9; i++) cout << board[i] << "\n";
}

/*



#include <iostream>

using namespace std;

int board[9][9];


// 0 1 2 // 3 4 5 // 6 7 8

void print_b() {
	cout << "\n";
	for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) cout<< board[i][j]<<" ";
			cout << "\n";
		}
	cout << "\n";
}

int is_dup(int i,int j, int k) {

	for (int garo = 0; garo < 9; garo++) if (board[i][garo] == k) return 1;
	for (int sero = 0; sero < 9; sero++) if (board[sero][j] == k) return 1;

	int rstart, rend, cstart, cend;
	if (i <= 2) {
		rstart = 0;
		rend = 2;
	}
	else if (i <= 5) {
		rstart = 3;
		rend = 5;
	}
	else {
		rstart = 6;
		rend = 8;
	}

	if (j <= 2) {
		cstart = 0;
		cend = 2;
	}
	else if (j <= 5) {
		cstart = 3;
		cend = 5;
	}
	else {
		cstart = 6;
		cend = 8;
	}
	for (int r = rstart; r <= rend; r++) {
		for (int c = cstart; c <= cend; c++) {
			if (board[r][c] == k) return 1;
		}
	}
	return 0;
}


int dfs() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == 0) {
				int k;
				for (k = 1; k <= 9; k++) {

					if (is_dup(i, j, k)) continue;
					board[i][j] = k;
					//print_b();
					if (dfs()) return 1;
					board[i][j] = 0;
				}
				if (k == 10) return 0;
			}
		}
	}
	return 1;
}

int main()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) cin >> board[i][j];
	}

	if (dfs()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) cout<< board[i][j]<<" ";
			cout << "\n";
		}
	}
}


*/