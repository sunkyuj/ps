#include <iostream>
#include <queue>
#include <tuple>

using namespace std;



int T,l,startX,startY,endX,endY;

int dx[8]={2,1,-1,-2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};


void bfs(queue <tuple<int,int,int>> q,int visited[][300]){
    while(!q.empty()){
        int y=get<0>(q.front()),x=get<1>(q.front());
        int depth=get<2>(q.front());
        q.pop();

        if(y==endY&&x==endX){
            cout<<depth<<"\n";
            return;
        }

        for(int i=0;i<8;i++){
            int nextY=y+dy[i];
            int nextX=x+dx[i];
            if(nextY>=0&&nextX>=0&&nextY<l&&nextX<l&&!visited[nextY][nextX]){
                q.push(make_tuple(nextY,nextX,depth+1));
                visited[nextY][nextX]=1;
            }
        }


    }
}

int main()
{
    cin>>T;
    while(T--){
        int visited[300][300]{};
        queue <tuple<int,int,int>> q;

        cin>>l>>startX>>startY>>endX>>endY;
        q.push(make_tuple(startY,startX,0));
        visited[startY][startX]=1;
        bfs(q,visited);
    }

    return 0;
}

/**

x+2 y+1
x+1 y+2
x-1 y+2
x-2 y+1
x-2 y-1
x-1 y-2
x+1 y-2
x+2 y-1

int dx[8]={2,1,-1,-2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
*/
