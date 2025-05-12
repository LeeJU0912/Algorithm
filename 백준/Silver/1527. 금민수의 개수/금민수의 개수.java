import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    static int A, B;
    static int ans;

    static void solve(long now) {
        if (now > B) return;
        if (now >= A) {
            ans++;
        }

        solve(now * 10 + 4);
        solve(now * 10 + 7);
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());

        solve(0);

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}