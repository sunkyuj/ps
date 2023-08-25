import java.util.*;


class Solution {
    public int solution(String dirs) {
        int answer = 0;
        int x=5,y=5,px=5,py=5;
        
        boolean[][][][] visit = new boolean[11][11][11][11];
        
        for(int i=0;i<dirs.length();i++){
            char dir=dirs.charAt(i);
            px=x;py=y;
            if(dir=='U'){
                if(y==10) continue;
                y++;
            }
            else if(dir=='D'){
                if(y==0) continue;
                y--;
            }
            else if(dir=='L'){
                if(x==0) continue;
                x--;
            }
            else if(dir=='R'){
                if(x==10) continue;
                x++;
            }
            if (!visit[px][py][x][y] && !visit[x][y][px][py]){
                visit[px][py][x][y] = true;
                visit[x][y][px][py] = true;
                answer++;
            }
        }
        
        return answer;
    }
}