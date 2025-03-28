import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[][] save = new int[3][N];
        int[] cnt = new int[101];
        int[] ans = new int[N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3; j++) {
                save[j][i] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < 3; i++) {
            Arrays.fill(cnt, 0);
            Arrays.stream(save[i]).forEach(num -> cnt[num]++);
            for (int j = 0; j < N; j++) {
                if (cnt[save[i][j]] == 1) {
                    ans[j] += save[i][j];
                }
            }
        }

        for (int i = 0; i < N; i++) {
            bw.write(ans[i] + "\n");
        }

        bw.flush();
        bw.close();
    }
}