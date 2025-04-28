import java.io.*;
import java.util.*;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {
    static Set<Long> set = new HashSet<>();
    static StringBuilder sb = new StringBuilder();

    public static long makeHash(String s) {
        long hash = 0;
        for (int i = 0; i < s.length(); i++) {
            hash = (hash << 5) | (s.charAt(i) - 'a');
        }
        return hash;
    }

    public static void makeStr(int cnt, int[] chk, char before, String s) {
        if (cnt == s.length()) {
            set.add(makeHash(sb.toString()));
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            if (chk[i] == 1 || s.charAt(i) == before) {
                continue;
            }
            chk[i] = 1;
            sb.append(s.charAt(i));
            makeStr(cnt + 1, chk, s.charAt(i), s);
            sb.deleteCharAt(sb.length() - 1);
            chk[i] = 0;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();
        int[] chk = new int[s.length()];

        for (int i = 0; i < s.length(); i++) {
            chk[i] = 1;
            sb.append(s.charAt(i));
            makeStr(1, chk, s.charAt(i), s);
            sb.deleteCharAt(0);
            chk[i] = 0;
        }

        bw.write(String.valueOf(set.size()));

        bw.flush();
        bw.close();
    }
}