#include <iostream>

using namespace std;



int f(int c,int stamp,int k){

    if(c==0&&stamp<k)
        return 0;

    else{
        c+=stamp/k;
        stamp=stamp%k+c;
        return c+f(0,stamp,k);
    }

}
//{8 3} = 8 (c 8) -> 8 2 (c 2 + 2) -> 8 2 1 (c 1)
/* {162 5} = 162 (c 162+0) -> 160 32 (c 32+2) -> 160 32 6 (c 6+4) -> 160 32 6 2 (c 0)
    {7 2} = 7 (c 7) -> 7 3 (c 3+1) ->7 3 2 (c 0)
*/
int main()
{
    int n,k;

    while(cin>>n>>k)
        cout<<f(n,0,k)<<"\n";

    return 0;
}

