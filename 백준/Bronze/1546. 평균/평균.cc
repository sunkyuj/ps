#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int n,i,a[1000],max=-1;
    float new_a[1000],sum=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        if(max<a[i]){
            max=a[i];
         //   index=i;
        }
    }
    for(i=0;i<n;i++){
        new_a[i]=(float)a[i]/max*100;
        sum+=new_a[i];
    }
    printf("%f",sum/n);


    return 0;
}

