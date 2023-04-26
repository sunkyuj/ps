
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for (int i = 1; i <= n; i++) {
            String[] ss = br.readLine().split(" ");
            System.out.printf("Case #%d: ",i);
            for (int j = ss.length - 1; j >= 0; j--) {
                System.out.print(ss[j]+" ");
            }
            System.out.println();
        }
    }
}