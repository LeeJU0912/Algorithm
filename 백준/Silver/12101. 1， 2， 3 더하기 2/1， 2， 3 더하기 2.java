import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {

    static int n, k;
    static int cnt = 0;
    static String ans;

    static void solve(int left, String s) {
        if (left < 0) return;
        if (left == 0) {
            cnt++;
            if (cnt == k) {
                ans = s;
            }
            return;
        }

        for (int i = 1; i <= 3; i++) {
            solve(left - i, s + '+' + i);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= 3; i++) {
            solve(n - i, String.valueOf(i));
        }

        if (ans == null) {
            bw.write("-1");
        }
        else bw.write(ans);

        bw.flush();
        bw.close();
    }
}