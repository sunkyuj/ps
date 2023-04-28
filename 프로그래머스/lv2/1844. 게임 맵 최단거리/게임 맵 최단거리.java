import java.util.*;

class Solution {
    public static class Node{
        public int y,x,cnt;
        public Node(int y, int x, int cnt){
            this.y = y;
            this.x = x;
            this.cnt = cnt;
        }  
    }
    
    public int solution(int[][] maps) {
        int answer = 0;
        int n = maps.length, m = maps[0].length;
        boolean[][] visit = new boolean[n][m];
        int[] dy = {1,0,-1,0};
        int[] dx = {0,1,0,-1};
        
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0,0,1));
        visit[0][0] = true;
        
        while(!q.isEmpty()){
            Node node = q.poll();
            int y=node.y,x=node.x,cnt=node.cnt;
            
            if(y==n-1 && x==m-1) return cnt;
            
            for(int k = 0; k<4; k++){
                int ny = y+dy[k];
                int nx = x+dx[k];
    
                if(ny>=0&&ny<n&&nx>=0&&nx<m && !visit[ny][nx] && maps[ny][nx] == 1){
                    q.add(new Node(ny,nx,cnt+1));
                    visit[ny][nx] = true;
                }          
            }
        }
        
        return -1;
    }
}