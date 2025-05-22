import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    static int S, K;
    static long ans = 1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        S = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        int N = S / K;
        int left = S % K;

        for (int i = 0; i < K; i++) {
            if (left > 0) {
                ans *= N + 1;
                left--;
            } else {
                ans *= N;
            }
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}