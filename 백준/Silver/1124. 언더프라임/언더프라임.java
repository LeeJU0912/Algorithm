import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {

    static boolean[] notSosu = new boolean[100001];
    static List<Integer> sosu = new ArrayList<>();

    static int A, B;
    static int[] chk = new int[100001];
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());

        notSosu[1] = true;
        for (int i = 2; i <= sqrt(B); i++) {
            if (notSosu[i]) continue;
            for (int j = 2; i * j <= B; j++) {
                notSosu[i * j] = true;
            }
        }

        for (int i = 2; i <= B; i++) {
            if (!notSosu[i]) sosu.add(i);
        }

        for (int i = 2; i <= B; i++) {
            for (int j : sosu) {
                if (i % j != 0) continue;
                chk[i] = chk[i / j] + 1;
                break;
            }
        }

        for (int i = A; i <= B; i++) {
            if (sosu.contains(chk[i])) ans++;
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}