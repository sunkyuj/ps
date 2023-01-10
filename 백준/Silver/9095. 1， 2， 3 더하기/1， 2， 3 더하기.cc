#include <iostream>

using namespace std;

int c=0;

/*

*/
void f(int n){

    if(n==1){
        c++;
    }
    else if(n==2){
        c=c+2;
    }
    else if(n==3){
        c=c+4;
    }
    else{
        f(n-1);
        f(n-2);
        f(n-3);
    }
}


int main()
{
    int T,n,i,ans[1000];
    cin >> T;
    for(i=0;i<T;i++){
        cin >>n;
        f(n);
        ans[i]=c;
        c=0;
    }
    for(i=0;i<T;i++)
        cout<<ans[i]<<endl;


    return 0;
}
