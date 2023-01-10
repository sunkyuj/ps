#include <iostream>

using namespace std;

int main()
{
    int h,m;
    cin>>h; cin>>m;
    if(m-45>=0) cout<<h<<" "<<m-45;
    else if(h>0) cout<<h-1<<" "<<m+15;
    else cout<<"23 "<<m+15;

    return 0;
}
