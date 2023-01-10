#include <iostream>

using namespace std;

int main()
{
    int T,a,b,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++){
        scanf("%d %d",&a,&b);
        printf("Case #%d: %d + %d = %d\n",i,a,b,a+b);
    }

    return 0;
}
