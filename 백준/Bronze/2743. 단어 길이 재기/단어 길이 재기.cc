#include <iostream>

using namespace std;

int main()
{
    char str[100];
    int i;
    cin >> str;
    for(i=0;str[i]!=NULL;i++);
    cout << i;
    return 0;
}
