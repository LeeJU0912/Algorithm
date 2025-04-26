import java.io.*;
import java.util.*;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = 0;
        while(true) {
            T++;
            int N = Integer.parseInt(br.readLine());
            if (N == 0) break;

            int[][] DP = new int[N][3];

            int[][] node = new int[N][3];
            for (int i = 0; i < N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 3; j++) {
                    node[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            DP[0][0] = 1_000_000_000;
            DP[0][1] = node[0][1];
            DP[0][2] = DP[0][1] + node[0][2];

            DP[1][0] = DP[0][1] + node[1][0];
            DP[1][1] = min(min(DP[0][1], DP[0][2]), DP[1][0]) + node[1][1];
            DP[1][2] = min(min(DP[0][1], DP[0][2]), DP[1][1]) + node[1][2];

            for (int i = 2; i < N; i++) {
                DP[i][0] = min(DP[i - 1][0], DP[i - 1][1]) + node[i][0];
                DP[i][1] = min(min(DP[i - 1][0], DP[i - 1][1]), min(DP[i - 1][2], DP[i][0])) + node[i][1];
                DP[i][2] = min(min(DP[i - 1][1], DP[i - 1][2]), DP[i][1]) + node[i][2];
            }

            bw.write(T + ". " + DP[N - 1][1]);
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}