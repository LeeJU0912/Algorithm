import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    static String s;
    static int[] DP = new int[1000];

    static void move(int idx, int hap, int turn) {
        if (DP[idx] <= hap) return;
        DP[idx] = hap;

        if (turn == 0) {
            for (int i = idx + 1; i < s.length(); i++) {
                if (s.charAt(i) == 'O') {
                    move(i, hap + (i - idx) * (i - idx), turn + 1);
                }
            }
        }
        else if (turn == 1) {
            for (int i = idx + 1; i < s.length(); i++) {
                if (s.charAt(i) == 'J') {
                    move(i, hap + (i - idx) * (i - idx), turn + 1);
                }
            }
        }
        else if (turn == 2) {
            for (int i = idx + 1; i < s.length(); i++) {
                if (s.charAt(i) == 'B') {
                    move(i, hap + (i - idx) * (i - idx), 0);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        s = br.readLine();

        Arrays.fill(DP, Integer.MAX_VALUE);
        move(0, 0, 0);

        if (DP[N - 1] == Integer.MAX_VALUE) {
            bw.write("-1");
        }
        else {
            bw.write(String.valueOf(DP[N - 1]));
        }

        bw.flush();
        bw.close();
    }
}