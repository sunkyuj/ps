#include <stdio.h>
#include <stdlib.h>
int C[50]={0};

int find_max_loc(int N, int *ap){//A에 쓸것
    int max=-1,i,loc;
    for(i=0;i<N;i++){
        if(C[i]==1){}
        else if(*(ap+i)>max){
            max=*(ap+i);
            loc=i;
        }
    }


    return loc;
}
int find_min_loc(int N, int *bp){//B에 쓸것
    int min=101,i,loc;
    for(i=0;i<N;i++){
        if(C[i]==1){}
        else if(*(bp+i)<min){
            min=*(bp+i);
            loc=i;
        }
    }

    return loc;
}
void swap(){

}

int main()
{
    int N,i,c=0,S=0,tmp,A_max_loc,B_min_loc;
    int A[50],B[50];
    int *ap=A,*bp=B;

    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&A[i]);
    for(i=0;i<N;i++)
        scanf("%d",&B[i]);

    while(1){
        for(i=0;i<N;i++){
            if(C[i]==1)
                c++;
        }
        if(c==N)
            break;

        else {
            A_max_loc=find_max_loc(N,ap);
            B_min_loc=find_min_loc(N,bp);

            tmp=A[A_max_loc];
            A[A_max_loc]=A[B_min_loc];
            A[B_min_loc]=tmp;

            C[B_min_loc]=1;
        }
        c=0;
    }



    for(i=0;i<N;i++)
        S+=A[i]*B[i];
/*
    for(i=0;i<N;i++)
        printf("%d ",A[i]);
    printf("\n");*/
    printf("%d",S);


    return 0;
}

/*

A에서 최댓값과 B에서 최솟값 매칭 find_max(),find_min(),swap()
C는 매칭이 완료됐는지 체크하는 용도

*/
