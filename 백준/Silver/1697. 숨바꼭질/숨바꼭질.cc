#include <iostream>
#include <queue>


using namespace std;
int n,k;
int visit[100001]={0};


void bfs(){

    queue <pair<int,int>> q;
    q.push({n,0});
    visit[n]=1;

    while(!q.empty()){
        int cur=q.front().first;
        int depth=q.front().second;
        q.pop();

        if(cur==k){cout<<depth; return;}


        if(cur-1>=0&&visit[cur-1]==0){q.push({cur-1,depth+1}); visit[cur-1]=1;}
        if(cur+1<=100000&&visit[cur+1]==0){q.push({cur+1,depth+1});visit[cur+1]=1;}
        if(cur*2<=100000&&visit[cur*2]==0){q.push({cur*2,depth+1});visit[cur*2]=1;}

    }
}

int main()
{
    cin>>n>>k;
    bfs();
    return 0;
}
