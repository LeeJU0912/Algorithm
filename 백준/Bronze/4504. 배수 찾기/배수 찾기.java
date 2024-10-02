import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        while(true) {
            int x = Integer.parseInt(br.readLine());

            if (x == 0) break;

            if (x % n == 0) {
                bw.write(x + " is a multiple of " + n + ".\n");
            }
            else {
                bw.write(x + " is NOT a multiple of " + n + ".\n");
            }
        }

        bw.flush();
        bw.close();
    }
}