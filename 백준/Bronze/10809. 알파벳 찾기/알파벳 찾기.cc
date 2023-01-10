#include <iostream>

using namespace std;

int main()
{
    int i, arr[26];
    char str[100];
    cin >> str;
    for(i=0;i<26;i++)
        arr[i]=-1;
    for(i=0;str[i]!=NULL;i++){
        if(arr[str[i]-97]==-1)
            arr[str[i]-97]=i;
    }
    for(i=0;i<26;i++)
        cout <<arr[i] <<" ";

    return 0;
}
