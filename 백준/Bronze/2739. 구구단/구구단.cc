#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    int n,i;
    cin>>n;
    for(i=1;i<=9;i++) printf("%d * %d = %d\n",n,i,n*i);
    return 0;
}
