#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>


using namespace std;

int main()
{
    int i,n,a,b,c;
    cin>>n;
    if(n==1000) n-=1;
    if(n<100){
        cout<<n;
    }
    else if(n<1000){
        int cnt=99;
        for(i=100;i<=n;i++){
            a=i/100;
            b=i/10%10;
            c=i%10;
            if(a-b==b-c) cnt++;
        }
        cout<<cnt;

    }




    return 0;
}


