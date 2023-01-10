#include <iostream>

using namespace std;

int g[1001][1001]{};
int visit[1001]={0};
int visit_bfs[1001]={0};
int q[1000];
int n,m,start,head=0,tail=-1;

void dfs(int start){
    int j;
    cout<<start<<" ";
    visit[start]=1;
    for(j=1;j<=n;j++) if(g[start][j]==1&&visit[j]==0) dfs(j);
}

void enq(int x){
    q[++tail]=x;
    visit_bfs[x]=1;
}
int deq(){
    return q[head++];
}

void bfs(){
    int j,x=deq();
    for(j=1;j<=n;j++){
        if(g[x][j]==1&&visit_bfs[j]==0) enq(j);
    }
    cout<<x<<" ";

}


int main()
{
    int i,v1,v2;
    cin>>n>>m>>start;
    for(i=1;i<=m;i++){
        cin>>v1>>v2;
        g[v1][v2]=g[v2][v1]=1;
    }
    dfs(start);
    cout<<"\n";

    enq(start);
    while(head<=tail) bfs();
    return 0;
}
