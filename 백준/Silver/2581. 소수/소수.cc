#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int m,n;
    int i,j,sum=0,min=10001;
    cin>>m>>n;
    for(i=m;i<=n;i++){
        if(i==2){
            sum+=2;
            min=2;
        }
        else if(i%2){
            for(j=2;j<=sqrt(i);j++){
                if(i%j==0)
                    break;
            }
            if(j>sqrt(i)){
                if(i!=1)
                    sum+=i;
                if(i<min)
                    min=i;
            }
        }
    }
    if(sum==0)
        cout<<"-1"<<"\n";
    else
        cout<<sum<<"\n"<<min<<"\n";
    return 0;
}
