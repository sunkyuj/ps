#include <iostream>
#include <bitset>
#include <string.h>
#include <stdlib.h>
using namespace std;


int main()
{

    int i=0,j,n,N,tmp,arr[10];
    cin >> n;

    while(n){
        arr[i]=n%10;
        n=n/10;
        i++;

    }
    N=i;


    for(i=0;i<N-1;i++){
        for(j=0;j<N-i-1;j++){
            if(arr[j]<arr[j+1]){
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }

    for(i=0;i<N;i++)
        cout << arr[i];



    return 0;
}
