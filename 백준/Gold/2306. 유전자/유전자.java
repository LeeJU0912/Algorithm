import java.io.*;
import java.util.*;

import static java.lang.Math.max;

public class Main {

    public static String s;
    public static int[][] DP = new int[501][501];

    public static int maxGene(int start, int end) {
        if (start >= end) return DP[start][end] = 0;
        if (DP[start][end] != -1) return DP[start][end];

        for (int i = start; i < end; i++) {
            DP[start][end] = max(DP[start][end], maxGene(start, i) + maxGene(i + 1, end));
        }

        if ((s.charAt(start) == 'a' && s.charAt(end) == 't') || (s.charAt(start) == 'g' && s.charAt(end) == 'c')) {
            DP[start][end] = max(DP[start][end], DP[start + 1][end - 1] + 2);
        }

        return DP[start][end];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        s = st.nextToken();

        for (int i = 0; i <= 500; i++) {
            for (int j = i; j <= 500; j++) {
                DP[i][j] = -1;
            }
        }

        bw.write(String.valueOf(maxGene(0, s.length() - 1)));

        bw.flush();
        bw.close();
    }
}