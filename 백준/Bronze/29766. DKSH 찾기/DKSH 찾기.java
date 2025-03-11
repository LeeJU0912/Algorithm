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

        String s = br.readLine();

        int ans = 0;
        for (int i = 0; i < s.length() - 3; i++) {
            String sub = s.substring(i, i + 4);

            if (sub.equals("DKSH")) {
                i += 3;
                ans++;
            }
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}