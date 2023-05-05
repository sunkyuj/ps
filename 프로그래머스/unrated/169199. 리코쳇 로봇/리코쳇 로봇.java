class Solution {
    int h,w;
    int ry,rx,gy,gx;
    int answer = Integer.MAX_VALUE;
    int[][] dp = new int[100][100];
    // int[][][] memo = new int[100][100][4];
    
    int[] dy = {1,0,-1,0};
    int[] dx = {0,-1,0,1};
    // boolean[][] visit = new boolean[100][100];
    
    public boolean inRange(int y,int x){
        return y>=0 && y<h && x>=0 && x<w;
    }
    
    public void f(String[] board, int y, int x, int cnt){
        if(y==gy&&x==gx) {
            answer = Math.min(answer,cnt);            
            return;
        }
        
        dp[y][x] = cnt;
        
        for(int k=0;k<4;k++){
            int ny=y, nx=x;
            while(inRange(ny+dy[k],nx+dx[k])&&board[ny+dy[k]].charAt(nx+dx[k])!='D'){
                ny+=dy[k];
                nx+=dx[k];
            }
            if(cnt+1<dp[ny][nx]) f(board,ny,nx,cnt+1);
        }
    }
    
    public int solution(String[] board) {

        h=board.length;
        w=board[0].length();
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++) dp[i][j] = Integer.MAX_VALUE;
        }
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(board[i].charAt(j)=='R'){
                    ry=i;
                    rx=j;
                }
                if(board[i].charAt(j)=='G'){
                    gy=i;
                    gx=j;
                }
            }
        }
        f(board,ry,rx,0);
        if(answer == Integer.MAX_VALUE) return -1;
        return answer;
    }
}