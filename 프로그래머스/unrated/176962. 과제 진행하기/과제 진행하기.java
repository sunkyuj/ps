import java.util.*;

class Solution {
    public class Node implements Comparable<Node>{
        String name;
        int start, playtime;
        Node(String name, int start, int playtime){
            this.name = name;
            this.start = start;
            this.playtime=playtime;
        }
        
        @Override
        public int compareTo(Node o){
            return this.start - o.start;
        }
    }
    public List<String> solution(String[][] plans) {
        List<String> answer = new ArrayList<>();
        List<Node> planList = new ArrayList<>();
        
        for(String[] plan: plans){
            int start = Integer.parseInt(plan[1].split(":")[0])*60 + Integer.parseInt(plan[1].split(":")[1]);
            planList.add(new Node(plan[0],start,Integer.parseInt(plan[2])));
        }
        Collections.sort(planList);
        
        
        Stack<Node> st = new Stack<>();
        int idx = 0;
        for(int t=0;t<=24*60;t++){
            
            if(!st.isEmpty()) st.peek().playtime--;
            if(!st.isEmpty() && st.peek().playtime==0) answer.add(st.pop().name);
            
            if(idx<plans.length && planList.get(idx).start==t) {
                st.push(planList.get(idx));
                idx++;
            }
        }
        while(!st.isEmpty()) answer.add(st.pop().name);
              
        return answer;
    }
}