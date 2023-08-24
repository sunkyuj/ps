class Solution {
    
    
    public String solution(String p) {
        
        // 1
        if(p.equals("")) return p;
        
        // 2
        int degree=0;
        int i=0;
        String u="";
        boolean isCorrect=true;
        do {
            u+=p.charAt(i);
            degree += (p.charAt(i) == '(')?1:-1;
            if(degree<0) isCorrect=false;
            i++;
        } while(degree!=0);
        String v = p.substring(i);
        
        // 3
        if(isCorrect) return u+solution(v);
        else{ // 4
            String newStr="(" + solution(v) + ")";
            u = u.substring(1,u.length()-1);
            for(i=0;i<u.length();i++){
                newStr+=(u.charAt(i)=='(')?')':'(';
            }
            return newStr;
        }
    }
}