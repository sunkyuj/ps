#include <iostream>
#include <bitset>
#include <string.h>

using namespace std;


int main()
{

    int i,n,sum=0,mul[500000];

    cin >> n;
    for(i=0;i<n;i++){
        cin >> mul[i];
        if(i==0){
            sum=sum+mul[i];
        }
        else{
            sum=sum+mul[i]-1;
        }

    }


    cout << sum;


    return 0;
}
