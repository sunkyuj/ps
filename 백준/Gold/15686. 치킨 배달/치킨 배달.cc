#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <cmath>

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;


int n, m;
int arr[51][51];

vector<pair<int, int>> house;
vector<pair<int, int>> chic;
int h_c[101][14];

int cl = INT_MAX;

int picked[14];
void f(int c,int cnt) {
	
	if (c == chic.size() && cnt != m) return; //끝까지 왔는데 다 안골랐으면 뒤로가기
	if (cnt == m) { //m개 골랐으니 고른 치킨집만 포함해서 각 h별로 치킨거리 구해서 합 내자
		
		int sum = 0;
		for (int h = 0; h < house.size(); h++) {
			int min_h_cl = INT_MAX;
			for (int c = 0; c < chic.size(); c++) {
				if (!picked[c]) continue;
				if (h_c[h][c] < min_h_cl) min_h_cl = h_c[h][c];
			}
			sum += min_h_cl;
		}
		if (sum < cl) cl = sum;
		return;
	}

	
	picked[c] = 1;
	f(c + 1, cnt + 1);//이번 c 고름
	picked[c] = 0;

	f(c + 1, cnt);//이번 c 안고름

	


}


int main()
{
	FIO;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				house.push_back({ i,j });
			}
			else if (arr[i][j] == 2) {
				chic.push_back({ i,j });
			}
		}
	}

	for (int h = 0; h < house.size(); h++) {
		for (int c = 0; c < chic.size(); c++) {
			h_c[h][c] = abs(house[h].first - chic[c].first) + abs(house[h].second - chic[c].second);
		}
	}


	f(0,0);
	cout << cl;

	/*
	m개의 치킨집만 남기고 폐업
	예를들어 6개의 치킨집 중 3개 빼고 폐업하면
	치킨집 0 1 2 3 4 5 중 3개를 선택해야함 (6 C 3 경우의수)

	3개를 골랐다고 치면 안고른 h_c에서 안고른 c들은 제외하고, 각 h별 치킨거리 최소인 값 선택

	
	*/
	


	
	//0 empty space, 1 house, 2 chicken
	
	/*
	1+2+2+3+3 = 11
	3+4+4+5+5 = 11+10 = 21
	32
	*/

}