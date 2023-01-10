#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
    string str;
    cin>>str;
    int i=0;
    while(str[i]){
        cout<<str[i];
        if((i+1)%10==0) cout<<"\n";
        i++;
    }
    return 0;
}
