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
        int B = Integer.parseInt(st.nextToken());

        List<Integer> broken = new ArrayList<>();
        for (int i = 0; i < B; i++) {
            int x = Integer.parseInt(br.readLine());
            broken.add(x);
        }

        Collections.sort(broken);

        int ans = Integer.MAX_VALUE;
        for (int i = 1; i <= N - K + 1; i++) {
            int from = i;
            int to = i + K - 1;

            int idx1 = -1, idx2 = -1;

            int start = 0;
            int end = broken.size() - 1;
            while (start <= end) {
                int mid = (start + end) / 2;

                if (broken.get(mid) >= from) {
                    end = mid - 1;
                    idx1 = mid;
                }
                else {
                    start = mid + 1;
                }
            }

            start = 0;
            end = broken.size() - 1;
            while (start <= end) {
                int mid = (start + end) / 2;

                if (broken.get(mid) <= to) {
                    start = mid + 1;
                    idx2 = mid;
                }
                else {
                    end = mid - 1;
                }
            }
            
            if (idx1 == -1 || idx2 == -1) {
                ans = 0;
                break;
            }

            ans = min(ans, (idx2 - idx1 + 1));
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}