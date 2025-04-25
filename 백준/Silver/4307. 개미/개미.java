import java.io.*;
import java.util.*;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        while(T > 0) {
            T--;

            StringTokenizer st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());

            List<Integer> list = new ArrayList<>();
            for(int i = 0; i < n; i++) {
                list.add(Integer.parseInt(br.readLine()));
            }

            int longest = 0;
            for (int i = 0; i < n; i++) {
                longest = max(longest, max(l - list.get(i), list.get(i)));
            }

            int shortest = 0;
            for (int i = 0; i < n; i++) {
                shortest = max(shortest, min(l - list.get(i), list.get(i)));
            }

            bw.write(shortest + " " + longest + "\n");
        }

        bw.flush();
        bw.close();
    }
}