import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        List<Integer> list = new ArrayList<>();

        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            list.add(Integer.parseInt(br.readLine()));
        }

        int size = 0;
        int target = N;
        for (int i = N - 1; i >= 0; i--) {
            if (list.get(i) == target) {
                target--;
                size++;
            }
        }

        bw.write(String.valueOf(N - size));

        bw.flush();
        bw.close();
    }
}