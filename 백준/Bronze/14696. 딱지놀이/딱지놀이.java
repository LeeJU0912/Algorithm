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


        int N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            int ans = -1;

            int[] aCnt = new int[4];
            int[] bCnt = new int[4];

            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            for (int j = 0; j < a; j++) {
                int x = Integer.parseInt(st.nextToken());
                aCnt[x - 1]++;
            }

            st = new StringTokenizer(br.readLine());
            int b = Integer.parseInt(st.nextToken());
            for (int j = 0; j < b; j++) {
                int x = Integer.parseInt(st.nextToken());
                bCnt[x - 1]++;
            }

            for (int j = 3; j >= 0; j--) {
                if (aCnt[j] != bCnt[j]) {
                    if (aCnt[j] > bCnt[j]) {
                        ans = 0;
                    }
                    else {
                        ans = 1;
                    }

                    break;
                }
            }

            if (ans == -1) {
                bw.write("D");
            }
            else if (ans == 0) {
                bw.write("A");
            }
            else if (ans == 1) {
                bw.write("B");
            }
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}