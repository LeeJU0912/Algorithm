import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String s;

        int N = sc.nextInt();

        for (int i = 0; i < N; i++) {
            s = sc.next();
            char[] arr = s.toCharArray();
            System.out.println(arr[0] - '0' + arr[2] - '0');
        }
    }
}