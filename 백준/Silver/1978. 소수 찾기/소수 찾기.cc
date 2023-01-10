#include <iostream>

using namespace std;

int main()
{
    int i,j,N,c=0;
    int arr[1000];
    cin>>N;
    for(i=0;i<N;i++){
        cin>>arr[i];
        if(arr[i]==2)
            c++;
        else {

            for(j=2;j<=arr[i]/2;j++){
                if(arr[i]%j==0)
                    break;
            }
            if(j==arr[i]/2+1){
                c++;
            }

        }

    }
    cout<<c;

    return 0;
}
