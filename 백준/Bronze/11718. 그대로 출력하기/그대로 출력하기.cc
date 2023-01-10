#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    char a[200][200];
    int i;
    for(i=0;i<100&&fgets(a[i],200,stdin);i++){
        cout<<a[i];
    }



    return 0;
}
