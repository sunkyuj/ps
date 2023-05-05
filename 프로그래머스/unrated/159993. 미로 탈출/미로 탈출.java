import java.util.*;

class Solution {
    public int[] dy = {1,0,-1,0};
    public int[] dx = {0,1,0,-1};
    public int startY,startX,endY,endX,lY,lX;
    public int n,m;
    
    public class Pair{
        public int y,x,cnt;
        public Pair(int y, int x, int cnt){
            this.y=y;
            this.x=x;
            this.cnt=cnt;
        }
    }
    
    public int bfs(int sy,int sx,int ey,int ex, String[] maps){
        boolean[][] visit = new boolean[n][m];
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(sy,sx,0));
        visit[sy][sx] = true;
        
        while(!q.isEmpty()){
            Pair p = q.poll();
            int y=p.y, x=p.x, cnt=p.cnt;
            if(y==ey&&x==ex) return cnt;
            for(int k=0;k<4;k++){
                int ny=y+dy[k], nx=x+dx[k];
                if(ny>=0&&ny<n&&nx>=0&&nx<m && !visit[ny][nx] && maps[ny].charAt(nx) != 'X'){
                    q.add(new Pair(ny,nx,cnt+1));
                    visit[ny][nx] = true;
                }
            }
        }
        
        return 0;
    }
    
    public int solution(String[] maps) {
        int answer = 0;
        n=maps.length;
        m=maps[0].length();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maps[i].charAt(j)=='S'){
                    startY = i;
                    startX = j;
                }
                if(maps[i].charAt(j)=='E'){
                    endY = i;
                    endX = j;
                }
                if(maps[i].charAt(j)=='L'){
                    lY = i;
                    lX = j;
                }
            }
        }
        int sl = bfs(startY,startX,lY,lX, maps);
        int le = bfs(lY,lX,endY,endX, maps);
        if(sl==0 || le==0) return -1;
        
        return sl+le;
    }
}