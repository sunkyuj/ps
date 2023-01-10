#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int e,s,m; /// 15 28 19
    cin>>e>>s>>m;
    /// n%15==e , e+ 15*q1 ==n , n-e == 15*q1
    /// n%28==s , s+ 28*q2 ==n , n-s == 28*q2  ;;;;;;;
    /// n%19==m , m+ 19*q3 ==n , n-m == 19*q3

    int i,j=0,k=0,tmp,cnt=0;

    for(i=0;i<=284;i++){
        tmp=s+28*i;
        while(e+15*j<=tmp){
            if(e+15*j==tmp){
                cnt++;
                break;
            }
            else j++;
        }
        j=0;

        while(m+19*k<=tmp){
            if(m+19*k==tmp){
                cnt++;
                break;
            }
            else k++;
        }
        k=0;

        if(cnt==2){
            cout<<tmp;
            break;
        }
        else cnt=0;

    }

    return 0;
}

