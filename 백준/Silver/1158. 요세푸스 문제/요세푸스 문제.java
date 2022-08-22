import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> arr =  new ArrayList<>();
        ArrayList<Integer> ans =  new ArrayList<>();

        int n;
        n = sc.nextInt();

        for (int i = 1; i <= n; i++) {
            arr.add(i);
        }

        int k;
        k = sc.nextInt();

        int temp = 0;

        while(!arr.isEmpty()) {

            temp += k - 1;
            if (temp < arr.size()) {
                ans.add(arr.get(temp));
                arr.remove(temp);
            }
            else {
                temp %= arr.size();
                ans.add(arr.get(temp));
                arr.remove(temp);
            }
        }


        System.out.print('<');
        for (int i = 0; i < ans.size() - 1; i++) {
            System.out.print(ans.get(i));
            System.out.print(", ");
        }
        System.out.print(ans.get(ans.size() - 1));
        System.out.print('>');
    }
}
