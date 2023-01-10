#include <iostream>

using namespace std;

int main()
{
    int i,t=0;
    char str[16];
    cin >> str;
    for(i=0;str[i]!=NULL;i++){
        if(str[i]<='C')
            t=t+3;
        else if(str[i]<='F')
            t=t+4;
        else if(str[i]<='I')
            t=t+5;
        else if(str[i]<='L')
            t=t+6;
        else if(str[i]<='O')
            t=t+7;
        else if(str[i]<='S')
            t=t+8;
        else if(str[i]<='V')
            t=t+9;
        else if(str[i]<='Z')
            t=t+10;

    }
    cout << t;
    return 0;
}
