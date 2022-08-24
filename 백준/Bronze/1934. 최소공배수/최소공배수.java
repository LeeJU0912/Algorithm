import java.util.Scanner;

public class Main {
    public static int GCD(int num1, int num2) {
        if (num2 == 0) {
            return num1;
        }
        else {
            return GCD(num2, num1 % num2);
        }
    }


    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        for (int i = 0; i < N; i++) {
            int A, B;
            A = sc.nextInt();
            B = sc.nextInt();

            int gcd = GCD(A, B);
            System.out.println(A * B / gcd);
        }
    }
}