import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        List<Integer> list = new ArrayList<>();
        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            list.add(Integer.parseInt(st.nextToken()));
        }

        int[] DP = new int[N];
        for (int i = 0; i < N; i++) {
            DP[i] = max(DP[i], 1);
            for (int j = i + 1; j < N; j++) {
                if (list.get(i) < list.get(j)) {
                    DP[j] = max(DP[j], DP[i] + 1);
                }
            }
        }

        bw.write(String.valueOf(IntStream.of(DP).max().getAsInt()));

        bw.flush();
        bw.close();
    }
}