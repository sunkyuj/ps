import java.util.*;

class Solution {
    public class Pair{
        int x,y;
        Pair(int x,int y){
            this.x=x;
            this.y=y;
        }
    }
    public List<Integer> solution(int m, int n, int startX, int startY, int[][] balls) {
        List<Integer> answer = new ArrayList<>();
        for(int[] ball: balls){
            int x = ball[0], y = ball[1];
            int min = Integer.MAX_VALUE;
            
            //4 방향
            //하 -startY;
            if(!(startX==x && startY>y))
                min = Math.min(min, (startX-x)*(startX-x) + (-startY-y)*(-startY-y));
            //상 startY + 2*(n-startY)
            if(!(startX==x && startY<y))
                min = Math.min(min, (startX-x)*(startX-x) + (startY + 2*(n-startY)-y)*(startY + 2*(n-startY)-y));
            
            //좌 -startX;
            if(!(startY==y && startX>x))
                min = Math.min(min, (-startX-x)*(-startX-x) + (startY-y)*(startY-y));
            
            //우 startX + 2*(m-startX)
            if(!(startY==y && startX<x))
                min = Math.min(min, (startX + 2*(m-startX)-x)*(startX + 2*(m-startX)-x) + (startY-y)*(startY-y));
            
            answer.add(min);
        }
        return answer;
    }
}