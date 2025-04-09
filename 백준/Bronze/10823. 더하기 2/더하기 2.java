import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder sb = new StringBuilder();
        while (true) {
            String s = br.readLine();
            if (s == null || s.isEmpty()) break;

            sb.append(s);
        }

        int ans = 0;
        StringTokenizer st = new StringTokenizer(sb.toString(), ",");
        while (st.hasMoreTokens()) {
            ans += Integer.parseInt(st.nextToken());
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}