#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<(a+b)%c<<"\n"<<(a%c+b%c)%c<<"\n"<<(a*b)%c<<"\n"<<(a%c*b%c)%c<<"\n";
    return 0;
}
