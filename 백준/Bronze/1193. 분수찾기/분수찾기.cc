#include <iostream>
#include <bitset>
#include <string.h>
#include <stdlib.h>
using namespace std;



int main()
{
    int x=1,y=1,n,i,up_zero=0,left_zero=0;
    cin >> n;
    for(i=2;i<=n;i++){
        if(up_zero==left_zero){
            x--;
            y++;
            if(x==0){
                up_zero++;
                x++;
            }

        }


        else if(up_zero>left_zero){
            x++;
            y--;
            if(y==0){
                left_zero++;
                y++;
            }
        }

    }
    cout << x << "/" << y;

    return 0;
}
