#include <iostream>
#include <bitset>
#include <string.h>
#include <stdlib.h>
using namespace std;



int main()
{
    int x,y,w,h,mx,my;
    cin >> x >> y >> w >> h;
    if(x<w-x)
        mx=x;
    else mx=w-x;

    if(y<h-y)
        my=y;
    else my=h-y;

    cout << min(mx,my);
    return 0;
}
