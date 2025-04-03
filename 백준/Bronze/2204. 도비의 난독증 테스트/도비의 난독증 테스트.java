import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0) break;

            String ans = br.readLine();
            String lowerAns = ans.toLowerCase();
            for (int i = 0; i < n - 1; i++) {
                String s = br.readLine();
                String lower = s.toLowerCase();

                if (lower.compareTo(lowerAns) < 0) {
                    ans = s;
                    lowerAns = lower;
                }
            }

            bw.write(ans);
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}