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
        long X = Long.parseLong(st.nextToken());

        st = new StringTokenizer(br.readLine());

        long ans = Long.MAX_VALUE;
        long now = X * Long.parseLong(st.nextToken());
        for (int i = 1; i < N; i++) {
            long next = X * Long.parseLong(st.nextToken());
            ans = min(ans, now + next);
            now = next;
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}