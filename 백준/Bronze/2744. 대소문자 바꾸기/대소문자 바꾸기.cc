#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for (auto &c : s)
    {
        if (c <= 'Z')
            c += 32;
        else
            c -= 32;
    }
    cout << s;
    return 0;
}
