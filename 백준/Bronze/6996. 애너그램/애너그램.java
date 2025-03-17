import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {

    private static boolean solve(String a, String b) {
        int[] cnt = new int[26];

        if (a.length() != b.length()) {
            return false;
        }

        for (int j = 0; j < a.length(); j++) {
            cnt[a.charAt(j) - 'a']++;
        }

        for (int j = 0; j < b.length(); j++) {
            if (--cnt[b.charAt(j) - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String a = st.nextToken().toLowerCase();
            String b = st.nextToken().toLowerCase();

            bw.write(a + " & " + b + " are " + (solve(a, b) ? "" : "NOT ") + "anagrams.");
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}