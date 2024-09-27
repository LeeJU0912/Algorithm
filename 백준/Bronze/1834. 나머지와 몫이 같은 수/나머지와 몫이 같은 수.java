import java.io.*;
import java.util.*;

public class Main {

    public static long N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());

        long ans = 0;

        for (int i = 1; i < N; i++) {
            ans += N * i + i;
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}