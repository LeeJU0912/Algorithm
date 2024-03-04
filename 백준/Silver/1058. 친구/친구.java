import java.awt.*;
import java.io.*;
import java.util.*;

import static java.lang.Math.max;

public class Main {

    static int N;
    static boolean[][] friend = new boolean[51][51];
    static boolean[] visited = new boolean[51];

    static int solve(int idx) {
        int count = 0;

        Queue<Point> q = new LinkedList<>();
        q.add(new Point(idx, 0));
        visited[idx] = true;

        while(!q.isEmpty()) {
            Point now = q.poll();

            if (now.y == 1) count++;
            else if (now.y == 2) {
                count++;
                continue;
            }

            for (int i = 0; i < N; i++) {
                if (!friend[now.x][i]) continue;
                if (visited[i]) continue;
                visited[i] = true;

                q.add(new Point(i, now.y + 1));
            }
        }

        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();

            for (int j = 0; j < N; j++) {
                if (s.charAt(j) == 'Y') friend[i][j] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            Arrays.fill(visited, false);
            ans = max(ans, solve(i));
        }

        bw.write(String.valueOf(ans));

        bw.flush();
    }
}