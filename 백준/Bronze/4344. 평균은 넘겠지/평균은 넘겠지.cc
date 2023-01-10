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
        int n,i,a[1000],cnt=0,sum=0;
        float avg;

        cin>>n;
        for(i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        avg=sum/n;
        for(i=0;i<n;i++){
            if(avg<a[i]) cnt++;
        }
        printf("%.3f%\n",(float)cnt/n*100);
    }
    return 0;
}

