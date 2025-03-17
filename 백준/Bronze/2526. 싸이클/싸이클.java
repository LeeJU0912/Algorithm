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

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());

        int[] answer = new int[1001];

        int now = N;
        int cnt = 1;
        while(true) {
            if (answer[now] != 0) {
                bw.write(String.valueOf(cnt - answer[now]));
                break;
            }

            answer[now] = cnt;
            cnt++;
            now *= N;
            now %= P;
        }

        bw.flush();
        bw.close();
    }
}