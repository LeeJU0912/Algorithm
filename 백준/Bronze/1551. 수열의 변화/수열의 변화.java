import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        List<Integer> save = new ArrayList<>();

        st = new StringTokenizer(br.readLine(), ",");
        for (int i = 0; i < N; i++) {
            save.add(Integer.parseInt(st.nextToken()));
        }

        for (int i = 0; i < K; i++) {
            List<Integer> tmp = new ArrayList<>();
            for (int j = 0; j < save.size() - 1; j++) {
                tmp.add(save.get(j + 1) - save.get(j));
            }

            save = tmp;
        }

        for (int i = 0; i < save.size() - 1; i++) {
            bw.write(save.get(i) + ",");
        }
        bw.write(String.valueOf(save.get(save.size() - 1)));

        bw.flush();
        bw.close();
    }
}