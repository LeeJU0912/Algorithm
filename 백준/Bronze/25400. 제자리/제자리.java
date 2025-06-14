import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] list = new int[N];
        for (int i = 0; i < N; i++) {
            list[i] = Integer.parseInt(st.nextToken());
        }

        int nowCnt = 1;
        for (int i = 0; i < N; i++) {
            if (list[i] == nowCnt) {
                nowCnt++;
            }
        }

        bw.write(String.valueOf(N - nowCnt + 1));
        
        bw.flush();
        bw.close();
    }
}