import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int ans = 0;
        while (N > 0) {
            ans <<= 1;
            ans |= (N & 1);
            N >>= 1;
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}