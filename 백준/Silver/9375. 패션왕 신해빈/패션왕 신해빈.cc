#include <iostream>
#include <unordered_map>

using namespace std;

int n;



int main()
{
	int T;
	cin >> T;
	while (T--) {
		
		cin >> n;
		
		int cat_n = 0;
		string categoies[30];
		int clothes[30] = {};

		for (int i = 0; i < n; i++) { //input
			string name, category;
			cin >> name >> category;
			
			int idx = -1;
			for (int i = 0; i < cat_n; i++) {
				if (categoies[i] == category) {
					idx = i;
					break;
				}
			}
			if (idx == -1) { //new cat
				categoies[cat_n] = category;
				clothes[cat_n]++;
				cat_n++;
			}
			else { //already in
				clothes[idx]++;
			}		
		}

		int sum = 1;
		for (int i = 0; i < cat_n; i++) {
			sum *= clothes[i] + 1;
		}
		sum--;
		cout << sum<<"\n";

	}
	

}
