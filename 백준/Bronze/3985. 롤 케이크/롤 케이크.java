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

        int L = Integer.parseInt(br.readLine());
        int N = Integer.parseInt(br.readLine());

        int[] chk = new int[L + 1];
        int[] cnt = new int[N + 1];

        int maxi = 0;
        int ans = 0;

        int maxi2 = 0;
        int ans2 = 0;

        for (int i = 1; i <= N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int p = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            if (maxi < (k - p + 1)) {
                maxi = k - p + 1;
                ans = i;
            }

            for (int j = p; j <= k; j++) {
                if (chk[j] != 0) continue;
                chk[j] = i;
                cnt[chk[j]]++;
            }
        }

        for (int i = 1; i <= N; i++) {
            if (maxi2 < cnt[i]) {
                maxi2 = cnt[i];
                ans2 = i;
            }
        }

        bw.write(String.valueOf(ans));
        bw.newLine();
        bw.write(String.valueOf(ans2));

        bw.flush();
        bw.close();
    }
}