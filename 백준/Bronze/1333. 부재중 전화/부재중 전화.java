import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());

        boolean[] chk = new boolean[5000];

        int hap = 0;
        for (int i = 0; i < N; i++) {
            for (int j = hap; j < hap + L; j++) {
                chk[j] = true;
            }
            hap += (L + 5);
        }

        int dHap = 0;
        while(true) {
            if (!chk[dHap]) {
                bw.write(String.valueOf(dHap));
                break;
            }
            dHap += D;
        }


        bw.flush();
        bw.close();
    }
}