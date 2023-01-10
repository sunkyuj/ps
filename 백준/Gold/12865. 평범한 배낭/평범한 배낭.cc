#include <iostream>

using namespace std;

typedef struct ITEM{
    int w;
    int v;
}ITEM;

int n,k;
int memo[101][100001]{};
ITEM item[101];


int dfs(int idx, int sum_w){

    if(idx==n) return 0; ///exit
    if(memo[idx][sum_w]>0) return memo[idx][sum_w];

    int n1=0;
    if(sum_w+item[idx].w<=k){ /// include item[idx]
        n1=item[idx].v+dfs(idx+1,sum_w+item[idx].w);
    }
    int n2=dfs(idx+1,sum_w);/// exclude item[idx]

    return memo[idx][sum_w]=max(n1,n2);
}
/**
4 7
6 13
4 8
3 6
5 12
*/
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>item[i].w>>item[i].v;
    cout<<dfs(0,0);
    return 0;
}


