import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= 26; i++) {
            graph.add(new ArrayList<>());
        }

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String a = st.nextToken();
            st.nextToken();
            String b = st.nextToken();

            graph.get(a.charAt(0) - 'a').add(b.charAt(0) - 'a');
        }

        int m = Integer.parseInt(br.readLine());
        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String a = st.nextToken();
            st.nextToken();
            String b = st.nextToken();

            boolean found = false;

            Queue<Integer> queue = new LinkedList<>();
            queue.add(a.charAt(0) - 'a');

            while(!queue.isEmpty()) {
                int now = queue.poll();
                if (now == b.charAt(0) - 'a') {
                    found = true;
                    break;
                }
                queue.addAll(graph.get(now));
            }

            if (found) {
                bw.write("T");
            }
            else {
                bw.write("F");
            }
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}