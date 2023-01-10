#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int C;
    cin>>C;
    while(C--){
        int r,i,j;
        char s[200];
        cin>>r;
        cin>>s;
        for(i=0;s[i]!='\0';i++){
            for(j=0;j<r;j++) cout<<s[i];
        }
        cout<<"\n";
    }
    return 0;
}

