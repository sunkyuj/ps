#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int m,n;
    int i,j;
    cin>>m>>n;
    for(i=m;i<=n;i++){
        if(i==2)
            cout<<2<<"\n";
        else if(i%2){
            for(j=2;j<=sqrt(i);j++){
                if(i%j==0)
                    break;
            }
            if(j>sqrt(i))
                if(i!=1)
                    cout<<i<<"\n";
        }
    }

    return 0;
}
