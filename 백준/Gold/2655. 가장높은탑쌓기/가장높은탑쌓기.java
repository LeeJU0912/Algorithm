import java.io.*;
import java.util.*;

import static java.lang.Math.max;

public class Main {

    // idx, minHeight, (sum, nowIdx, beforeHeight)
    static int[][][] DP = new int[101][10001][3];

    static class bricks {
        int idx, bottom, height, weight;

        public bricks(int idx, int bottom, int height, int weight) {
            this.idx = idx;
            this.bottom = bottom;
            this.height = height;
            this.weight = weight;
        }
    }

    static List<bricks> save = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            save.add(new bricks(i, Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken())));
        }

        save.sort((o1, o2) -> o2.weight - o1.weight);

        DP[0][save.get(0).bottom][0] = save.get(0).height;
        DP[0][save.get(0).bottom][1] = save.get(0).idx;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= 10000; j++) {
                DP[i][j] = DP[i - 1][j];
            }
            for (int j = save.get(i).bottom + 1; j <= 10000; j++) {
                if (DP[i - 1][j][0] + save.get(i).height > DP[i][save.get(i).bottom][0]) {
                    DP[i][save.get(i).bottom][0] = DP[i - 1][j][0] + save.get(i).height;
                    DP[i][save.get(i).bottom][1] = save.get(i).idx;
                    DP[i][save.get(i).bottom][2] = j;
                }
            }
        }

        int maxi = 0;
        int ans = 0;
        for (int i = 0; i <= 10000; i++) {
            if (maxi < DP[n - 1][i][0]) {
                maxi = DP[n - 1][i][0];
                ans = i;
            }
        }

        List<Integer> calc = new ArrayList<>();

        calc.add(DP[n - 1][ans][1]);

        ans = DP[n - 1][ans][2];

        for (int i = n - 2; i >= 0; i--) {
            if (DP[i][ans][1] == 0) break;
            if (calc.get(calc.size() - 1) != DP[i][ans][1]) calc.add(DP[i][ans][1]);
            ans = DP[i][ans][2];
        }

        bw.write(calc.size() + "\n");
        for (int i : calc) {
            bw.write(i + "\n");
        }

        bw.flush();
        bw.close();
    }
}