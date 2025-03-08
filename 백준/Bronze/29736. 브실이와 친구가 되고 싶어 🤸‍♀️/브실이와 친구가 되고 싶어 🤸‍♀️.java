import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        int K = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());

        int mini = max(A, K - X);
        int maxi = min(B, K + X);

        int ans = maxi - mini + 1;

        if (ans <= 0) {
            bw.write("IMPOSSIBLE");
        }
        else {
            bw.write(String.valueOf(ans));
        }

        bw.flush();
        bw.close();
    }
}