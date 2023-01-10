#include <iostream>
#include <queue>

using namespace std;

int n,m,cc=0;
int arr[1001][1001]{};
int visited[1001]={0};
queue <int> q;

void bfs(){
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int j=1;j<=n;j++){
            if(arr[cur][j]==1&&!visited[j]){
                q.push(j);
                visited[j]=1;
            }
        }
    }
}

void find_node(){
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]==1&&!visited[j]){
                q.push(j);
                visited[j]=1;
                cc++;
                bfs();
            }
        }
    }
}

int main()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++) arr[i][i]=1;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        arr[u][v]=arr[v][u]=1;
    }
    cc++;
    q.push(1);
    visited[1]=1;
    bfs();

    find_node();
    cout<<cc;


    return 0;
}
