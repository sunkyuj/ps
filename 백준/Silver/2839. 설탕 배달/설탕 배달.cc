#include <iostream>
#include <climits>

using namespace std;

int n,min_bag=INT_MAX;
int visited[5001]={0};

void dfs(int cur,int bag){

    if(cur==n){
         min_bag=min(bag,min_bag);
         return;
    }

    if(cur+5<=n&&!visited[cur+5]){
        visited[cur+5]=1;
        dfs(cur+5,bag+1);
    }
    if(cur+3<=n&&!visited[cur+3]){
        visited[cur+3]=1;
        dfs(cur+3,bag+1);
    }
}

int main()
{
    cin>>n;
    dfs(0,0);

    if(min_bag!=INT_MAX) cout<<min_bag;
    else cout<<-1;
    return 0;
}
