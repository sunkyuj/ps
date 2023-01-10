#include <iostream>
using namespace std;

typedef struct twoint{
    unsigned int zero;
    unsigned int one;
}twoint;

twoint memo[41];

twoint f(int n) {
    if (memo[n].zero!=-1){//한번 그 값을 계산 했던거임!
        return memo[n];
    }
    if (n==0){
        memo[n].zero=1;
        memo[n].one=0;
        return memo[n];
    }
    else if (n==1){
        memo[n].zero=0;
        memo[n].one=1;
        return memo[n];
    }
    else if (memo[n].zero==-1){//한번도 그 값을 계산 안했음!
        memo[n].zero=f(n-1).zero+f(n-2).zero;
        memo[n].one=f(n-1).one+f(n-2).one;
        return memo[n];
    }
}
int main()
{
    int i,T,N;
    int input[10000];
    for(i=0;i<41;i++){
        memo[i].zero=-1;
        memo[i].one=-1;
    }
    cin>>T;
    /*
    for(i=0;i<T;i++)
        cin>>input[i];
    for(i=0;i<T;i++)
        f(input[i]);
    for(i=0;i<T;i++)
        cout<<memo[input[i]].zero <<" "<<memo[input[i]].one<< endl;
    */
    for(i=0;i<T;i++){
        cin>>N;
        f(N);
        cout<<memo[N].zero<<" "<<memo[N].one<<endl;
    }
    return 0;
}
