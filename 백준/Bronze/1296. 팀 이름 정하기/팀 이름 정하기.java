import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int ansVal = -1;
        String ans = "";

        int[] cnt = new int[4];

        String s = br.readLine();
        cntStr(cnt, s);

        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            s = br.readLine();
            int[] cnt2 = new int[4];

            cntStr(cnt2, s);

            int calc = 1;
            for (int j = 0; j < 4; j++) {
                for (int k = j + 1; k < 4; k++) {
                    calc *= ((cnt[j] + cnt2[j]) + (cnt[k] + cnt2[k]));
                }
            }
            calc %= 100;

            if (ansVal <= calc) {
                if (ansVal == calc) {
                    if (ans.compareTo(s) > 0) {
                        ans = s;
                    }
                }
                else {
                    ans = s;
                }
                ansVal = calc;
            }
        }

        bw.write(ans);

        bw.flush();
        bw.close();
    }

    private static void cntStr(int[] cnt, String s) {
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'L') {
                cnt[0]++;
            }
            else if (s.charAt(i) == 'O') {
                cnt[1]++;
            }
            else if (s.charAt(i) == 'V') {
                cnt[2]++;
            }
            else if (s.charAt(i) == 'E') {
                cnt[3]++;
            }
        }
    }
}