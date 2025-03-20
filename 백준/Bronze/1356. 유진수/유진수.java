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

        String N = br.readLine();

        boolean isAns = false;
        for (int i = 0; i < N.length() - 1; i++) {
            String a = N.substring(0, i + 1);
            String b = N.substring(i + 1, N.length());

            long calcA = 1;
            long calcB = 1;

            for (int j = 0; j < a.length(); j++) {
                calcA *= (a.charAt(j) - '0');
            }
            for (int j = 0; j < b.length(); j++) {
                calcB *= (b.charAt(j) - '0');
            }

            if (calcA == calcB) {
                isAns = true;
                break;
            }
        }

        if (isAns) {
            bw.write("YES");
        }
        else {
            bw.write("NO");
        }

        bw.flush();
        bw.close();
    }
}