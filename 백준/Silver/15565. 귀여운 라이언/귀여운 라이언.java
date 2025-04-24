import java.io.*;
import java.util.*;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        List<Integer> list = new ArrayList<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int a = Integer.parseInt(st.nextToken());
            if (a == 1) {
                list.add(i);
            }
        }

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i <= list.size() - K; i++) {
            ans = min(ans, list.get(i + K - 1) - list.get(i) + 1);
        }

        if (ans == Integer.MAX_VALUE) {
            bw.write("-1");
        }
        else {
            bw.write(String.valueOf(ans));
        }

        bw.flush();
        bw.close();
    }
}