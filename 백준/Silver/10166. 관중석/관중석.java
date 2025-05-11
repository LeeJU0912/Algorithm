import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        Set<Integer> set = new HashSet<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int D1 = Integer.parseInt(st.nextToken());
        int D2 = Integer.parseInt(st.nextToken());

        for (int i = D1; i <= D2; i++) {
            for (int j = 1; j <= i; j++) {
                set.add(720000 * j / i);
            }
        }

        bw.write(String.valueOf(set.size()));

        bw.flush();
        bw.close();
    }
}