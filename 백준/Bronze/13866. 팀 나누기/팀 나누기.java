import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());

        int[] save = new int[4];
        save[0] = Integer.parseInt(st.nextToken());
        save[1] = Integer.parseInt(st.nextToken());
        save[2] = Integer.parseInt(st.nextToken());
        save[3] = Integer.parseInt(st.nextToken());

        int hap = save[0] + save[1] + save[2] + save[3];

        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                ans = min(ans, abs(hap - save[i] - save[j] - save[i] - save[j]));
            }
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}