import java.io.*;
import java.util.*;

import static java.lang.Math.min;

public class Main {
    static class point {
        int x, y;

        public point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static class INFO implements Comparable<INFO> {
        int x, y, time, key;

        public INFO(int time, int key, int x, int y) {
            this.x = x;
            this.y = y;
            this.time = time;
            this.key = key;
        }

        @Override
        public int compareTo(INFO o) {
            return (this.time < o.time ? -1 : 1);
        }
    }

    static int N, M;
    static int[][] board = new int[51][51];
    static boolean[][][] visited = new boolean[51][51][2 << 6];
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};

    static point start;

    static int ans = Integer.MAX_VALUE;

    static void solve() {
        PriorityQueue<INFO> pq = new PriorityQueue<>();

        pq.add(new INFO(0, 0, start.x, start.y));

        while(!pq.isEmpty()) {
            int now_time = pq.peek().time;
            int now_key = pq.peek().key;
            int now_x = pq.peek().x;
            int now_y = pq.poll().y;

            if (board[now_x][now_y] == 2) {
                ans = min(ans, now_time);
                continue;
            }


            for (int i = 0; i < 4; i++) {
                int next_x = now_x + dx[i];
                int next_y = now_y + dy[i];

                if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;
                if (board[next_x][next_y] == 1) continue;
                if (visited[next_x][next_y][now_key]) continue;
                visited[next_x][next_y][now_key] = true;

                if (board[next_x][next_y] >= 20) {
                    int shift = (1 << (board[next_x][next_y] - 20));
                    if ((now_key & shift) == 0) continue;
                    pq.add(new INFO(now_time + 1, now_key, next_x, next_y));
                }
                else if (board[next_x][next_y] >= 10) {
                    int shift = (1 << (board[next_x][next_y] - 10));
                    int next_key = (now_key | shift);
                    pq.add(new INFO(now_time + 1, next_key, next_x, next_y));
                }
                else {
                    pq.add(new INFO(now_time + 1, now_key, next_x, next_y));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));



        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            String s = br.readLine();
            for (int j = 0; j < M; j++) {
                if (s.charAt(j) == '#') {
                    board[i][j] = 1;
                }
                else if (s.charAt(j) >= 'a' && s.charAt(j) <= 'f') {
                    board[i][j] = s.charAt(j) - 'a' + 10;
                }
                else if (s.charAt(j) >= 'A' && s.charAt(j) <= 'F') {
                    board[i][j] = s.charAt(j) - 'A' + 20;
                }
                else if (s.charAt(j) == '0') {
                    start = new point(i, j);
                }
                else if (s.charAt(j) == '1') {
                    board[i][j] = 2;
                }
            }
        }

        solve();

        bw.write((ans == Integer.MAX_VALUE ? "-1" : String.valueOf(ans)));

        bw.flush();
        bw.close();
    }
}