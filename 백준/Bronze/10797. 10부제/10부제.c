#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cars[5],n,i,cnt=0;
    scanf("%d",&n);
    scanf("%d %d %d %d %d",&cars[0],&cars[1],&cars[2],&cars[3],&cars[4]);
    for(i=0;i<5;i++){
        if(n==cars[i]) cnt++;
    }
    printf("%d",cnt);

    return 0;
}
