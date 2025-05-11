import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        boolean[][] chk = new boolean[2001][2001];

        StringTokenizer st = new StringTokenizer(br.readLine());
        int D1 = Integer.parseInt(st.nextToken());
        int D2 = Integer.parseInt(st.nextToken());

        int ans = 0;
        for (int i = D1; i <= D2; i++) {
            for (int j = 1; j <= i; j++) {
                int gcd = gcd(i, j);

                if (chk[j / gcd][i / gcd]) {
                    continue;
                }
                chk[j / gcd][i / gcd] = true;
                ans++;
            }
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}