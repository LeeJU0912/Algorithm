import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        boolean[] notSosu = new boolean[1299710];
        for (int i = 2; i * i <= 1299709; i++) {
            if (notSosu[i]) continue;
            for (int j = 2; i * j <= 1299709; j++) {
                int calc = i * j;
                if (notSosu[calc]) continue;
                notSosu[calc] = true;
            }
        }

        List<Integer> sosu = new ArrayList<>();
        for (int i = 2; i <= 1299709; i++) {
            if (notSosu[i]) continue;
            sosu.add(i);
        }

        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int k = Integer.parseInt(br.readLine());

            int lower_bound = 0;
            int upper_bound = sosu.size() - 1;

            int start = 0;
            int end = sosu.size() - 1;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (sosu.get(mid) <= k) {
                    lower_bound = mid;
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            start = 0;
            end = sosu.size() - 1;
            while (start <= end) {
                int mid = (start + end) / 2;
                if (sosu.get(mid) >= k) {
                    upper_bound = mid;
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }

            bw.write(String.valueOf(sosu.get(upper_bound) - sosu.get(lower_bound)));
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}