import java.io.*;
import java.util.*;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {

    static int leafNodeDepth = 0;
    static List<List<Integer>> graph = new ArrayList<>();

    static void search(int node, int before, int depth) {
        int cnt = 0;
        for (int next : graph.get(node)) {
            if (next != before) {
                cnt++;
                search(next, node, depth + 1);
            }
        }

        if (cnt == 0) {
            leafNodeDepth += depth;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < N - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            graph.get(a).add(b);
            graph.get(b).add(a);
        }

        search(1, 0, 0);

        if (leafNodeDepth % 2 == 0) {
            bw.write("No");
        }
        else {
            bw.write("Yes");
        }

        bw.flush();
        bw.close();
    }
}