import java.io.*;
import java.util.*;

public class Main {
    static class INFO implements Comparable<INFO> {
        int from, to, dist;

        INFO (int from, int to, int dist) {
            this.from = from;
            this.to = to;
            this.dist = dist;
        }

        public int compareTo(INFO o) {
            return this.dist - o.dist;
        }
    }
    static int N, M;

    static int[] dist = new int[1001];

    static ArrayList<INFO>[] save = new ArrayList[1001];

    static boolean[] visited = new boolean[1001];

    static ArrayList<INFO> ans = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        Arrays.fill(dist, (int) 1e9);

        for (int i = 1; i <= N; i++) {
            save[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());

            save[A].add(new INFO(A, B, C));
            save[B].add(new INFO(B, A, C));
        }

        PriorityQueue<INFO> pq = new PriorityQueue<>();

        pq.add(new INFO(1, 1, 0));
        dist[1] = 0;

        while(!pq.isEmpty()) {
            INFO now = pq.poll();

            for (INFO next : save[now.from]) {
                if (now.dist + next.dist >= dist[next.to]) continue;
                dist[next.to] = now.dist + next.dist;

                pq.add(new INFO(next.to, next.to, dist[next.to]));
            }
        }

        Queue<INFO> q = new LinkedList<>();
        q.add(new INFO(1, 1, 0));
        visited[1] = true;

        while(!q.isEmpty()) {
            INFO now = q.poll();

            for (INFO next : save[now.from]) {
                if (now.dist + next.dist == dist[next.to]) {
                    if (visited[next.to]) continue;
                    visited[next.to] = true;
                    ans.add(next);
                    q.add(new INFO(next.to, next.to, dist[now.from] + next.dist));
                }
            }
        }

        bw.write(String.valueOf(ans.size()));
        bw.newLine();

        for (INFO now : ans) {
            bw.write(now.from + " " + now.to);
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}