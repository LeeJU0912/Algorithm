import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {

    static class INFO implements Comparable<INFO> {
        int cnt;
        int x;

        public INFO(int cnt, int x) {
            this.cnt = cnt;
            this.x = x;
        }

        @Override
        public int compareTo(INFO o) {
            return cnt - o.cnt;
        }
    }
    static PriorityQueue<INFO> pq = new PriorityQueue<>();
    static int A, B, N, M;
    static boolean[] DP = new boolean[100001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        
        pq.add(new INFO(0, N));
        while(!pq.isEmpty()) {
            INFO now = pq.poll();

            if (now.x == M) {
                bw.write(String.valueOf(now.cnt));
                break;
            }

            int nextCnt = now.cnt + 1;

            if (now.x - 1 >= 0 && !DP[now.x - 1]) {
                pq.add(new INFO(nextCnt, now.x - 1));
                DP[now.x - 1] = true;
            }
            if (now.x + 1 <= 100000 && !DP[now.x + 1]) {
                pq.add(new INFO(nextCnt, now.x + 1));
                DP[now.x + 1] = true;
            }
            if (now.x - A >= 0 && !DP[now.x - A]) {
                pq.add(new INFO(nextCnt, now.x - A));
                DP[now.x - A] = true;
            }
            if (now.x + A <= 100000 && !DP[now.x + A]) {
                pq.add(new INFO(nextCnt, now.x + A));
                DP[now.x + A] = true;
            }
            if (now.x - B >= 0 && !DP[now.x - B]) {
                pq.add(new INFO(nextCnt, now.x - B));
                DP[now.x - B] = true;
            }
            if (now.x + B <= 100000 && !DP[now.x + B]) {
                pq.add(new INFO(nextCnt, now.x + B));
                DP[now.x + B] = true;
            }
            if (now.x * A <= 100000 && !DP[now.x * A]) {
                pq.add(new INFO(nextCnt, now.x * A));
                DP[now.x * A] = true;
            }
            if (now.x * B <= 100000 && !DP[now.x * B]) {
                pq.add(new INFO(nextCnt, now.x * B));
                DP[now.x * B] = true;
            }
        }

        bw.flush();
        bw.close();
    }
}