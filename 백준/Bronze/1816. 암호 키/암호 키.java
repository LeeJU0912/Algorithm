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
        for (int i = 0; i < N; i++) {
            long a = Long.parseLong(br.readLine());

            boolean notAns = false;

            for (int j = 2; j <= 1000000; j++) {
                if (a % j == 0) {
                    notAns = true;
                    break;
                }
            }

            if (notAns) {
                bw.write("NO\n");
            }
            else {
                bw.write("YES\n");
            }
        }

        bw.flush();
        bw.close();
    }
}