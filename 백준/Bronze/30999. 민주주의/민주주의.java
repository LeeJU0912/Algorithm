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

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int ans = 0;

        for (int i = 0; i < N; i++) {
            String s = br.readLine();

            int cnt = 0;
            for (int j = 0; j < M; j++) {
                if (s.charAt(j) == 'O') cnt++;
            }

            if (cnt > M / 2) ans++;
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}