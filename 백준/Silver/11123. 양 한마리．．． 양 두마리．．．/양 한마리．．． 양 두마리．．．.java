import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int H = Integer.parseInt(st.nextToken());
            int W = Integer.parseInt(st.nextToken());

            char[][] board = new char[H][W];
            for (int i = 0; i < H; i++) {
                String s = br.readLine();
                for (int j = 0; j < W; j++) {
                    board[i][j] = s.charAt(j);
                }
            }

            boolean[][] visited = new boolean[H][W];

            int ans = 0;

            int[] dx = {0, 0, 1, -1};
            int[] dy = {1, -1, 0, 0};

            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (board[i][j] == '#' && !visited[i][j]) {
                        ans++;
                        Queue<int[]> queue = new LinkedList<>();
                        queue.offer(new int[]{i, j});
                        visited[i][j] = true;
                        while (!queue.isEmpty()) {
                            int[] xy = queue.poll();
                            int x = xy[0];
                            int y = xy[1];

                            for (int k = 0; k < 4; k++) {
                                int nx = x + dx[k];
                                int ny = y + dy[k];
                                if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && board[nx][ny] == '#') {
                                    visited[nx][ny] = true;
                                    queue.offer(new int[]{nx, ny});
                                }
                            }
                        }
                    }
                }
            }

            bw.write(String.valueOf(ans));
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}