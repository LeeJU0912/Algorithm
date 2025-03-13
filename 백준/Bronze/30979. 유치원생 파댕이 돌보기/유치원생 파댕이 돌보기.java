import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        int hap = 0;
        for (int i = 0; i < N; i++) {
            hap += Integer.parseInt(st.nextToken());
        }

        if (hap >= T) {
            bw.write("Padaeng_i Happy");
        }
        else {
            bw.write("Padaeng_i Cry");
        }

        bw.flush();
        bw.close();
    }
}