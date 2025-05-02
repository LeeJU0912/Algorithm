import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    static List<Integer> g = new ArrayList<>();
    static Set<Integer> s = new HashSet<>();

    static void hap(int idx, int val) {
        if (idx < 0) return;

        for (int i = idx; i >= 0; i--) {
            int calc = val + g.get(i);
            if (calc > 0) s.add(calc);
            hap(i - 1, calc);

            calc = val - g.get(i);
            if (calc > 0) s.add(calc);
            hap(i - 1, calc);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int k = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < k; i++) {
            g.add(Integer.parseInt(st.nextToken()));
        }
        g.sort(Comparator.naturalOrder());

        for (int i = 0; i < k; i++) {
            s.add(g.get(i));
        }

        for (int i = k - 1; i >= 0; i--) {
            hap(i - 1, g.get(i));
            hap(i - 1, -g.get(i));
        }

        int sum = g.stream().mapToInt(i -> i).sum();
        bw.write(String.valueOf(sum - s.size()));

        bw.flush();
        bw.close();
    }
}