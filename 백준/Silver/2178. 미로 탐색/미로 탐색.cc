#include <iostream>
#include <limits.h>
#include <utility>
#include <queue>

using namespace std;


int n,m;
string arr[100];
int visit[100][100]{};
int min_ans=INT_MAX;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

queue <pair<int,int>> q;


void bfs(int i, int j){

    q.push(pair<int,int>(i,j));
    visit[i][j]=1;
    while(!q.empty()){

        int y=q.front().first,x=q.front().second;
        q.pop();

        for(int k=0;k<4;k++){
            int next_y=y+dy[k], next_x=x+dx[k]; ///direction r u l d
            if(next_y>=0&&next_y<n&&next_x>=0&&next_x<m){ ///on range
                if(visit[next_y][next_x]==0&&arr[next_y][next_x]=='1'){
                    visit[next_y][next_x]=visit[y][x]+1;
                    q.push(pair<int,int>(next_y,next_x));
                }
            }
        }
    }
}

int main()
{

    cin>>n>>m;
    int i;
    for(i=0;i<n;i++) cin>>arr[i];
    bfs(0,0);
    cout<<visit[n-1][m-1];
    return 0;
}
