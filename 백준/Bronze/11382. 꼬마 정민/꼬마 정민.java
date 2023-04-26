
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] s = bf.readLine().split(" ");
        long answer = 0;
        for (int i = 0; i < s.length; i++) {
            answer += Long.parseLong(s[i]);
        }
        System.out.println(answer);
    }
}
