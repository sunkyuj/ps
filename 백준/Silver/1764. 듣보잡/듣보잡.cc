#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int n, m;
string d[500001]; //n

vector <string> db;

int bin(string key) {
	int s = 0, e = n - 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (d[mid] > key) {
			e = mid - 1;
		}
		else if (d[mid] < key) {
			s = mid + 1;
		}
		else return 1;
	}
	return 0;
}


int main()
{
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> d[i];
	sort(d, d + n);

	for (int i = 0; i < m; i++) {
		string b;
		cin >> b;
		if (bin(b)) db.push_back(b);
	}
	sort(db.begin(),db.end());
	cout << db.size() << "\n";
	for (int i = 0; i < db.size(); i++) cout << db[i] << "\n";
	
	
	

}