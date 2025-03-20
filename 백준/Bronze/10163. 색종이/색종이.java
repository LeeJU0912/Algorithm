import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[][] chk = new int[1001][1001];

        int N = Integer.parseInt(br.readLine());

        int[] cnt = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            for (int j = a; j <= a + c - 1; j++) {
                for (int k = b; k <= b + d - 1; k++) {
                    chk[j][k] = i;
                }
            }
        }

        for (int i = 0; i <= 1000; i++) {
            for (int j = 0; j <= 1000; j++) {
                cnt[chk[i][j]]++;
            }
        }

        for (int i = 1; i <= N; i++) {
            bw.write(String.valueOf(cnt[i]));
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}