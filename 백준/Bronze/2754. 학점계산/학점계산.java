import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        char[] arr = new char[2];

        arr = sc.next().toCharArray();

        if (arr[0] == 'A' && arr[1] == '+') {
            System.out.println("4.3");
        }
        else if (arr[0] == 'A' && arr[1] == '0') {
            System.out.println("4.0");
        }
        else if (arr[0] == 'A' && arr[1] == '-') {
            System.out.println("3.7");
        }
        else if (arr[0] == 'B' && arr[1] == '+') {
            System.out.println("3.3");
        }
        else if (arr[0] == 'B' && arr[1] == '0') {
            System.out.println("3.0");
        }
        else if (arr[0] == 'B' && arr[1] == '-') {
            System.out.println("2.7");
        }
        else if (arr[0] == 'C' && arr[1] == '+') {
            System.out.println("2.3");
        }
        else if (arr[0] == 'C' && arr[1] == '0') {
            System.out.println("2.0");
        }
        else if (arr[0] == 'C' && arr[1] == '-') {
            System.out.println("1.7");
        }
        else if (arr[0] == 'D' && arr[1] == '+') {
            System.out.println("1.3");
        }
        else if (arr[0] == 'D' && arr[1] == '0') {
            System.out.println("1.0");
        }
        else if (arr[0] == 'D' && arr[1] == '-') {
            System.out.println("0.7");
        }
        else {
            System.out.println("0.0");
        }
    }
}