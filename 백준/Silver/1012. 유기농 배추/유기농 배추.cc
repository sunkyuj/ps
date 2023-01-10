#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue <pair<int,int>> q;

int m,n,k,bbug=0;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};

bool inRange(int y, int x){
    return (y>=0&&x>=0&&y<n&&x<m)?true:false;
}

void bfs(int arr[][50], int visited[][50]){
    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();


        for(int i=0;i<4;i++){
            int next_y=y+dy[i];
            int next_x=x+dx[i];

            if(inRange(next_y,next_x)&&!visited[next_y][next_x]&&arr[next_y][next_x]==1){
                q.push({next_y,next_x});
                visited[next_y][next_x]=bbug;

            }
        }
    }
}

void find_cabb(int arr[][50], int visited[][50]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1&&!visited[i][j]){
                bbug++;
                q.push({i,j});
                visited[i][j]=bbug;
                bfs(arr,visited);
            }
        }
    }
}


int main()
{
    int T;
    cin>>T;
    while(T--){
        int arr[50][50]{};
        int visited[50][50]{};
        int y,x;

        cin>>m>>n>>k;
        for(int i=1;i<=k;i++) {cin>>x>>y;arr[y][x]=1;}
        find_cabb(arr,visited);
        cout<<bbug<<"\n";
        bbug=0;
    }

    return 0;
}
