#include <iostream>
#include <bitset>
#include <string.h>
#include <stdlib.h>
using namespace std;
int c=0;
int cycle(int N,int n){
    int ten,one;

    if(c!=0){
        if(N==n)
            return c;
    }
    c++;

    ten=n%10;
    one=(n/10+n%10)%10;
    n=ten*10+one;

    return cycle(N,n);
}


int main()
{
    int n,N;
    cin >> N;
    n=N;

    cout << cycle(N,n);

    return 0;
}
