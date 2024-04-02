import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static List<Integer> basic = new ArrayList<>();
    static List<Integer>[] saving = new ArrayList[101];
    static List<Integer>[] counter = new ArrayList[101];
    static boolean[] chk = new boolean[101];
    static int[][] DP = new int[101][101];

    static void get_cost(int a, int b) {
        int before = saving[a].get(b);
        int multi = counter[a].get(b);
        for (int i = 1; i < N; i++) {
            DP[a][i] += DP[before][i] * multi;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        for (int i = 1; i <= N; i++) {
            saving[i] = new ArrayList<>();
            counter[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            int X, Y, K;

            StringTokenizer st = new StringTokenizer(br.readLine());
            X = Integer.parseInt(st.nextToken());
            Y = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());

            saving[X].add(Y);
            counter[X].add(K);
        }

        for (int i = 1; i < N; i++) {
            if (saving[i].isEmpty()) {
                basic.add(i);
                DP[i][i] = 1;
                chk[i] = true;
            }
        }

        boolean skip = true;
        while(skip) {
            skip = false;
            for (int i = 1; i <= N; i++) {
                if (chk[i]) continue;

                boolean c = false;
                for (int j = 0; j < saving[i].size(); j++) {
                    if (!chk[saving[i].get(j)]) {
                        c = true;
                        break;
                    }
                }
                if (c) continue;
                
                for (int j = 0; j < saving[i].size(); j++) {
                    get_cost(i, j);
                }
                chk[i] = true;
                skip = true;
            }
        }

        for (int i = 0; i < basic.size(); i++) {
            bw.write(basic.get(i) + " " + DP[N][basic.get(i)] + '\n');
        }

        bw.flush();
        bw.close();
    }
}