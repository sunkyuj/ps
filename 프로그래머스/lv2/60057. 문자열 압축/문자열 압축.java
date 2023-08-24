import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 100000;
        int len = s.length();
        
        for(int n=1;n<=len;n++){//1000
            String newStr="";
            String prev="";
            int cnt=0;
            int i;
            for(i=0;i<s.length();i+=n){
                String cut;
                if(i+n<=s.length()) cut = s.substring(i,i+n);
                else break;
                
                if(cnt==0){
                    cnt++;
                    prev=cut;
                    continue;
                }
                
                if(cut.equals(prev)) cnt++;
                else {
                    if(cnt>=2) newStr+=Integer.toString(cnt);
                    newStr+=prev;
                    cnt=1;
                    prev=cut;
                }
            }
            if(cnt>=2) newStr+=Integer.toString(cnt);
            newStr+=prev;
            
            if(i<s.length()) newStr+=s.substring(i);
            
            answer = Math.min(answer,newStr.length());
        }
        
        return answer;
    }
}