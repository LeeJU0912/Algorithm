import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    static class Bridge {
        int a, b;

        public Bridge(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }
    static List<List<Integer>> graph = new ArrayList<>();
    static List<Bridge> bridges = new ArrayList<>();
    static Set<Integer> leafNodes = new HashSet<>();
    static Set<Bridge> leafVertices = new HashSet<>();

    static void getLeafNodes() {
        for (int i = 1; i < graph.size(); i++) {
            if (graph.get(i).size() == 1) {
                leafNodes.add(i);
                leafVertices.add(new Bridge(i, graph.get(i).get(0)));
            }
        }
    }

    static boolean chkVertex(int a) {
        return !leafNodes.contains(a);
    }

    static boolean chkBridge(int a, int b) {
        return !(leafVertices.contains(new Bridge(a, b)) | leafVertices.contains(new Bridge(b, a)));
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

            bridges.add(new Bridge(a, b));
        }

        getLeafNodes();

        int q = Integer.parseInt(br.readLine());
        for (int i = 0; i < q; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int order = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());

            if (order == 1) {
                if (chkVertex(a)) {
                    bw.write("yes\n");
                }
                else {
                    bw.write("no\n");
                }
            }
            else if (order == 2) {
                if (chkBridge(bridges.get(a - 1).a, bridges.get(a - 1).b)) {
                    bw.write("yes\n");
                }
                else {
                    bw.write("no\n");
                }
            }
        }

        bw.flush();
        bw.close();
    }
}