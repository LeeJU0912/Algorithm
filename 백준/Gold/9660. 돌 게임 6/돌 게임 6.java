import java.io.*;
import java.util.*;

public class Main {
    static Long N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        N = Long.parseLong(st.nextToken());

        boolean ans = false;

        if (N == 1) {
            ans = true;
        }
        else if (N > 2) {
            N -= 2;

            Long mod = N % 7;

            if (mod >= 1 && mod <= 4 || mod == 6) ans = true;
        }

        if (ans) {
            bw.write("SK");
        }
        else {
            bw.write("CY");
        }
        bw.newLine();


        bw.flush();
    }
}