import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static ArrayList<Integer>[] imp;
    static int[] ans = new int[100001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        imp = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            imp[i] = new ArrayList<>();
        }

        st = new StringTokenizer(br.readLine());

        Queue<Integer> q = new LinkedList<>();

        for (int i = 1; i <= N; i++) {
            int boss = Integer.parseInt(st.nextToken());
            if (boss == -1) {
                q.add(i);
                continue;
            }
            imp[boss].add(i);
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            ans[a] += b;
        }

        while(!q.isEmpty()) {
            int now = q.poll();

            if (imp[now].isEmpty()) continue;
            for (int i = 0; i < imp[now].size(); i++) {
                ans[imp[now].get(i)] += ans[now];
                q.add(imp[now].get(i));
            }
        }

        for (int i = 1; i <= N; i++) {
            bw.write(String.valueOf(ans[i]));
            bw.write(' ');
        }

        bw.flush();
    }
}