
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int problem = 0;
        while(true){
            String s = br.readLine();
            if (s.equals("고무오리 디버깅 끝")) break;
            else if (s.equals("문제")) problem++;
            else if(s.equals("고무오리")){
                if(problem==0) problem+=2;
                else problem-=1;
            }
        }
        if(problem!=0) System.out.print("힝구");
        else System.out.print("고무오리야 사랑해");
    }
}