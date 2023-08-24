import java.util.*;

class Solution {
    public long solution(long w, long h) {
        long answer = w*h;
        long gcd = GCD(w,h);
        long ww = w/gcd, hh = h/gcd;
        long hit = ww+hh-1;
        
        answer -= gcd*hit;
        
        return answer;
    }
    
    public long GCD(long a, long b){
        long tmp;
        while(b!=0){
            tmp = a;
            a = b;
            b = tmp%b;
        }
        return a;
    }
}