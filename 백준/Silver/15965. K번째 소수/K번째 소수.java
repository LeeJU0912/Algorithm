import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int K = Integer.parseInt(br.readLine());

        boolean[] notSosu = new boolean[10000001];

        for (int i = 2; i <= sqrt(10000000); i++) {
            if (notSosu[i]) continue;
            for (int j = 2; i * j <= 10000000; j ++) {
                notSosu[i * j] = true;
            }
        }

        List<Integer> list = new ArrayList<>();
        for (int i = 2; i <= 10000000; i++) {
            if (notSosu[i]) continue;
            list.add(i);
        }

        bw.write(String.valueOf(list.get(K - 1)));

        bw.flush();
        bw.close();
    }
}