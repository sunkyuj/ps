import java.util.*;

class Solution {
    public int n,m;
    public int[] dy = {1,0,-1,0};
    public int[] dx = {0,-1,0,1};
    public boolean[][] visit = new boolean[101][101];
    
    public class Pair{
        public int y, x;
        public Pair(int y,int x){
            this.y=y;
            this.x=x;
        }
    }
    public int bfs(String[] maps,int i, int j){
        int cnt = 0;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(i,j));
        visit[i][j] = true;
        while(!q.isEmpty()){
            Pair p = q.poll();
            int y = p.y, x = p.x;
            cnt += Integer.parseInt(maps[y].substring(x,x+1));
            
            for(int k = 0; k<4; k++){
                int ny = y+dy[k] , nx = x+dx[k];
                if(ny>=0&&ny<n&&nx>=0&&nx<m &&!visit[ny][nx] && maps[ny].charAt(nx)!="X".charAt(0)){
                    q.add(new Pair(ny,nx));
                    visit[ny][nx] = true;
                }
            }
        }
        return cnt;
    }
    public int[] solution(String[] maps) {
        List<Integer> answerList = new ArrayList<>();
        n = maps.length; 
        m = maps[0].length();
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                if(maps[i].charAt(j)!="X".charAt(0)&&!visit[i][j]) answerList.add(bfs(maps,i,j));
            }
        }
        if(answerList.size()==0){
            int[] answer = {-1};
            return answer;
        }
        answerList.sort(Comparator.naturalOrder());
        int[] answer = new int[answerList.size()];
        for(int i=0; i<answerList.size(); i++) answer[i]=answerList.get(i);
        return answer;
    }
}