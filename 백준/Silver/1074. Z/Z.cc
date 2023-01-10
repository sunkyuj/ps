#include <iostream>
#include<math.h>

using namespace std;

int num=0;

void z(int N,int r,int c){
    int quadrant;
    int powerNumber=pow(2,N-1); // N 2 pN 2, N 3 pN 4

    if (N==0)
        return;

    else if(N>0){

        if(r<powerNumber&&c<powerNumber){
            quadrant=1;
        }
        if(r<powerNumber&&c>=powerNumber){
            quadrant=2;
            c-=powerNumber;
        }
        if(r>=powerNumber&&c<powerNumber){
            quadrant=3;
            r-=powerNumber;
        }
        if(r>=powerNumber&&c>=powerNumber){
            quadrant=4;
            r-=powerNumber;
            c-=powerNumber;
        }
        num+=powerNumber*powerNumber*(quadrant-1);
        --N;
        z(N,r,c);
    }
}

int main()
{
    int N,r,c;
    cin >> N>>r>>c;
    z(N,r,c);
    cout<<num<<endl;

    return 0;
}
