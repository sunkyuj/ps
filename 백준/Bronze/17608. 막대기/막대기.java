
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[100001];
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int answer = 0;
        int cur = 0;
        for(int i = n-1; i>=0;i--){
            if(cur<arr[i]){
                cur = arr[i];
                answer++;
            }
        }
        System.out.println(answer);

    }
}