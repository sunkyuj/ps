#include <iostream>

using namespace std;

int f(int k,int n){
    int sum=0,i;
    if (k==0){
        for(i=1;i<=n;i++)
            sum=i;
    }

    else {
        while(--k>=0){
            while(n){
                sum+=f(k,n);
                n--;
            }
        }
    }
    return sum;
}

int main()
{
    int T,k,n,i,ans[1000];
    cin >> T;
    for(i=0;i<T;i++){
        cin >>k>>n;
        ans[i]=f(k,n);
    }
    for(i=0;i<T;i++)
        cout<<ans[i]<<endl;

    return 0;
}
/*

21:1,22:4,23:10
11:1,12:3,13:6
01:1,02:2,03:3
*/
