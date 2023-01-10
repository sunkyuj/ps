#include <iostream>
#include <map>


using namespace std;

int n;

multimap <int, string> mm;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;

		mm.insert({ age,name });
		
	}
	multimap<int, string>::iterator iter;

	for (iter = mm.begin(); iter != mm.end(); iter++) {
		cout << iter->first << " " << iter->second << "\n";
	}



}
