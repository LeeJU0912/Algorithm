import java.awt.*;
import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static int[][] board = new int[50][50];
    static boolean[][] visited = new boolean[50][50];
    static int[][] DP = new int[50][50];
    static int[] dx = {1, -1, -1, 1, -1, 1, 0, 0};
    static int[] dy = {1, -1, 1, -1, 0, 0, 1, -1};

    static Queue<Point> q = new LinkedList<>();

    static int bfs() {
        int ans = 0;

        while(!q.isEmpty()) {
            int now_x = q.peek().x;
            int now_y = q.peek().y;
            q.poll();

            ans = Math.max(ans, DP[now_x][now_y]);

            for (int i = 0; i < 8; i++) {
                int next_x = now_x + dx[i];
                int next_y = now_y + dy[i];

                if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;
                if (visited[next_x][next_y]) continue;
                visited[next_x][next_y] = true;

                DP[next_x][next_y] = DP[now_x][now_y] + 1;
                q.add(new Point(next_x, next_y));
            }
        }

        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());

        N = Integer.parseInt(stringTokenizer.nextToken());
        M = Integer.parseInt(stringTokenizer.nextToken());

        for (int i = 0; i < N; i++) {
            stringTokenizer = new StringTokenizer(br.readLine());

            for (int j = 0; j < M; j++) {
                board[i][j] = Integer.parseInt(stringTokenizer.nextToken());
                if (board[i][j] == 1) {
                    q.add(new Point(i, j));
                    visited[i][j] = true;
                }
            }
        }

        bw.write(String.valueOf(bfs()));

        bw.flush();
    }
}