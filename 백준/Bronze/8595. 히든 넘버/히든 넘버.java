import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();

        long ans = 0;

        int now = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                now *= 10;
                now += (s.charAt(i) - '0');
            }
            else {
                ans += now;
                now = 0;
            }
        }

        ans += now;

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}