#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    int i,j,c=0;

    cin>>n;
    while(n){
        for(i=n+1;i<=n*2;i++){
            if(i==2)
                c++;
            else if(i%2){
                for(j=2;j<=sqrt(i);j++){
                    if(i%j==0)
                        break;
                }
                if(j>sqrt(i)){
                    if(i!=1)
                        c++;

                }
            }
        }
        cout<<c<<"\n";
        c=0;
        cin>>n;
    }
    return 0;
}
