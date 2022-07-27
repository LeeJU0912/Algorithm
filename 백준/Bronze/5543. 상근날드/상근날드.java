import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int mini = 2000;
        int mini2 = 2000;

        for (int i = 0; i < 3; i++) {
            int n = sc.nextInt();
            if (n < mini) {
                mini = n;
            }
        }
        for (int i = 0; i < 2; i++) {
            int n = sc.nextInt();
            if (n < mini2) {
                mini2 = n;
            }
        }
        System.out.println(mini + mini2 - 50);
    }
}