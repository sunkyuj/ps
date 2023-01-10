#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

int n;
string str[1001];

void f() {
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (str[j].size() > str[j+1].size()) swap(str[j], str[j+1]); //1
			else if (str[j].size() == str[j+1].size()) {
				int A = 0, B = 0, len = str[j].size();
				for (int k = 0; k < len; k++) {
					if (str[j][k] >= '0' && str[j][k] <= '9') A += str[j][k] - '0';
					if (str[j+1][k] >= '0' && str[j+1][k] <= '9') B += str[j+1][k] - '0';
				}
				if (A > B) swap(str[j], str[j+1]); //2
				else if (A == B) { //3
					if (strcmp(str[j].c_str(), str[j+1].c_str()) > 0) swap(str[j], str[j+1]);
				}
			}
		}
	}
}

int main()
{
	FIO;
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> str[i];
	f();
	for (int i = 0; i < n; i++) cout << str[i]<<"\n";

}