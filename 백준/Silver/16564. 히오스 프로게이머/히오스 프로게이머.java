import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            list.add(Integer.parseInt(br.readLine()));
        }

        long start = 1;
        long end = Integer.MAX_VALUE;
        int ans = 0;
        while (start <= end) {
            long mid = (start + end) / 2;
            long left = K;
            
            for (int i = 0; i < N; i++) {
                if (list.get(i) > mid) continue;
                left -= mid - list.get(i);
            }
            if (left < 0) {
                end = mid - 1;

            } else {
                start = mid + 1;
                ans = (int) mid;
            }
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}