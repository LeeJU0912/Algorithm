import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        for (int i = 1; i <= n; i++) {
            System.out.print("Case #" + i + ": ");
            String[] s = br.readLine().split(" ");

            for (int j = s.length - 1; j >= 0; j--) {
                if (j == 0) {
                    System.out.print(s[j]);
                }
                else System.out.print(s[j] + " ");
            }
            System.out.println();
        }
        
        bw.flush();
        bw.close();
    }
}