import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        int ans = min(A, B + 1) + min(A - 1, B);

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}