import java.util.*;

class Solution {
    public class Node{
        public String s;
        public int cnt;
        public Node(String s, int cnt){
            this.s = s;
            this.cnt = cnt;
        }
    }
    public boolean change(String s1, String s2){
        int cnt=0;
        for(int i=0;i<s1.length();i++){
            if(s1.charAt(i) != s2.charAt(i)){
                cnt++;
            }
        }
        if(cnt>=2) return false;
        return true;

    }
    
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        Queue<Node> q = new LinkedList<>();
        Set<String> set = new HashSet<>();

        q.add(new Node(begin,0));
        set.add(begin);
        
        while(!q.isEmpty()){
            Node node = q.poll();
            String s = node.s;
            int cnt = node.cnt;
            // System.out.printf("%s %d \n",s,cnt);
            
            if(s.equals(target)) return cnt;
            for(String word: words){
                if(!set.contains(word)&&change(s,word)) {
                    q.add(new Node(word,cnt+1));
                    set.add(word);
                }
            }
        }

        
        return answer;
    }
}