#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n;
//중위와 후위가 주어질 것 --> 전위를 구하라

int in[100001];
int post[100001];//후위
vector<int> ans;
int in_idx[100001];
//int post_idx[100001];



void f(int in_s,int in_e, int post_cur_idx) {
	int cur_val = post[post_cur_idx];
	int CURi=in_idx[cur_val];
	cout << cur_val << " ";
	
	int post_child_idx = post_cur_idx - 1; //r idx
	int child = post[post_child_idx]; //r
	bool has_r = false;

	//vector<int> L, R;
	
	if (CURi < in_idx[child] && in_idx[child] <= in_e) { //has r -> print l first then r
		has_r = true;
		post_child_idx -= (in_e - CURi);
		child = post[post_child_idx];
	}
	
	if (in_s <= in_idx[child] && in_idx[child] < CURi) { //has l
		f(in_s, CURi - 1, post_child_idx); //print l
	}
	if(has_r) f(CURi + 1, in_e, post_cur_idx - 1);//print r


}

int main()
{
	FIO;


	cin >> n;
	fill(in_idx, in_idx + 1 + n, -1);

	for (int i = 0; i < n; i++) {
		cin >> in[i];
		in_idx[in[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> post[i];	
		//post_idx[post[i]] = i;
	}

	f(0, n - 1, n - 1);
	//for (int i = 0; i < n; i++) cout << ans[i] << " ";

}
