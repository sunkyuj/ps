#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

string table[25];
int n,ans[314]={0},danji=0;
int visited[25][25]{};
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};

queue <pair<int,int>> q;

bool inRange(int a, int b){
    return (a>=0&&a<n&&b>=0&&b<n)?true:false;
}

void bfs(){

    while(!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();


        for(int i=0;i<4;i++){
            int next_y=y+dy[i];
            int next_x=x+dx[i];

            if(inRange(next_y,next_x)&&table[next_y][next_x]=='1'&&!visited[next_y][next_x]){
                q.push({next_y,next_x});
                ans[danji]++;
                visited[next_y][next_x]=danji;
            }
        }
    }
}

void find_house(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(table[i][j]=='1'&&!visited[i][j]){
                danji++;
                q.push({i,j});
                ans[danji]++;
                visited[i][j]=danji;
                bfs();
            }
        }
    }
}



int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>table[i];
    find_house();

    cout<<danji<<"\n";
    sort(ans,ans+danji+1);
    for(int i=1;i<=danji;i++) cout<<ans[i]<<"\n";


    return 0;
}
