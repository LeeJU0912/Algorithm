import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    static String A, B;
    static boolean[] visited = new boolean[10];

    static int bInt;
    static int ans;

    static void make(int cnt, int val) {
        if (cnt == B.length()) {
            if (val >= bInt) return;
            ans = max(ans, val);
            return;
        }

        for (int i = 0; i < A.length(); i++) {
            if (visited[i]) continue;
            visited[i] = true;
            make(cnt + 1, val * 10 + (A.charAt(i) - '0'));
            visited[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        A = st.nextToken();
        B = st.nextToken();
        Character[] charArray = new Character[A.length()];
        for (int i = 0; i < A.length(); i++) {
            charArray[i] = A.charAt(i);
        }
        Arrays.sort(charArray, Collections.reverseOrder());
        A = Arrays.stream(charArray).sequential().collect(StringBuilder::new, StringBuilder::append, StringBuilder::append).toString();
        bInt = Integer.parseInt(B);

        if (A.length() > B.length()) {
            bw.write("-1");
        }
        else if (A.length() < B.length()) {
            bw.write(A);
        }
        else {
            for (int i = 0; i < A.length(); i++) {
                if (A.charAt(i) == '0') continue;
                visited[i] = true;
                make(1, (A.charAt(i) - '0'));
                visited[i] = false;
            }
            if (ans == 0) bw.write("-1");
            else bw.write(String.valueOf(ans));
        }

        bw.flush();
        bw.close();
    }
}