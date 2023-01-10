#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{

    while(1){
        string s;
        getline(cin,s);
        if(!s.compare("END")) break;
        int l=s.length();
        int i;
        for(i=l-1;i>=0;i--){
            cout<<s[i];
        }
        cout<<"\n";
    }
    return 0;
}


