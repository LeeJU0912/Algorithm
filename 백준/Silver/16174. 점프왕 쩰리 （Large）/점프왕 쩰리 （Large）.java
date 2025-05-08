import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    static class Node {
        int x, y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static int[][] board = new int[64][64];
    static boolean[][] visited = new boolean[64][64];
    static int[] dx = {0, 1};
    static int[] dy = {1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0, 0));

        boolean found = false;

        while (!q.isEmpty()) {
            Node now = q.poll();

            if (board[now.x][now.y] == -1) {
                found = true;
                break;
            }

            for (int i = 0; i < 2; i++) {
                int nextX = now.x + dx[i] * board[now.x][now.y];
                int nextY = now.y + dy[i] * board[now.x][now.y];

                if (nextX < 0 || nextX >= 64 || nextY < 0 || nextY >= 64) continue;
                if (visited[nextX][nextY]) continue;
                visited[nextX][nextY] = true;

                q.add(new Node(nextX, nextY));
            }
        }

        if (found) {
            bw.write("HaruHaru");
        }
        else {
            bw.write("Hing");
        }

        bw.flush();
        bw.close();
    }
}