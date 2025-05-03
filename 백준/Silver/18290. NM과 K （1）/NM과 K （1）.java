import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    static int N, M, K;
    static int[][] board = new int[10][10];
    static boolean[][] visited = new boolean[10][10];

    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    static int ans = Integer.MIN_VALUE;

    static boolean cantGo(int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[nx][ny]) return true;
        }
        return false;
    }

    static void search(int x, int y, int cnt, int hap) {
        if (cnt == K) {
            ans = max(ans, hap);
            return;
        }

        for (int i = y + 2; i < M; i++) {
            int nx = x;
            int ny = i;
            if (cantGo(nx, ny)) continue;
            visited[nx][ny] = true;
            search(nx, ny, cnt + 1, hap + board[nx][ny]);
            visited[nx][ny] = false;
        }

        for (int i = x + 1; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int nx = i;
                int ny = j;
                if (cantGo(nx, ny)) continue;
                visited[nx][ny] = true;
                search(nx, ny, cnt + 1, hap + board[nx][ny]);
                visited[nx][ny] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                visited[i][j] = true;
                search(i, j, 1, board[i][j]);
                visited[i][j] = false;
            }
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}