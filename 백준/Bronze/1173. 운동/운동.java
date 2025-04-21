import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());

        if (m + T > M) {
            bw.write("-1");
            bw.flush();
            bw.close();
            return;
        }

        int ans = 0;

        int cntN = 0;
        int nowM = m;
        while(cntN < N) {
            if (nowM + T > M) {
                nowM = max(m, nowM - R);
            }
            else {
                nowM += T;
                cntN++;
            }

            ans++;
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}