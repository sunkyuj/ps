#include <iostream>


using namespace std;

int stack[20000];
int top = -1;
int n;

int main()
{
	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int val;
			cin >> val;
			stack[++top] = val;
		}
		else if (cmd == "pop") {
			if (top == -1) cout << -1 << "\n";
			else cout << stack[top--] << "\n";
		}
		else if (cmd == "size") {
			cout << top + 1 << "\n";
		}
		else if (cmd == "empty") {
			if (top == -1) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (cmd == "top") {
			if (top == -1) cout << -1 << "\n";
			else cout<< stack[top] << "\n";
		}
	}
}
