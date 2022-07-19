import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner put = new Scanner(System.in);

        String s = put.next();

        char[] arr = s.toCharArray();

        for (int i = 0; i < arr.length; i++) {
            if (i != 0 && i % 10 == 0) {
                System.out.print("\n");
            }
            System.out.print(arr[i]);
        }
    }
}