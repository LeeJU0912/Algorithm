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

        Set<String> st = new HashSet<>();
        List<String> save = new ArrayList<>();

        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            String s = br.readLine();
            st.add(s);
            save.add(s);
        }

        for (int i = 0; i < N; i++) {
            String s = new StringBuilder(save.get(i)).reverse().toString();
            if (st.contains(s)) {
                bw.write(s.length() + " " + s.charAt(s.length() / 2));
                break;
            }
        }

        bw.flush();
        bw.close();
    }
}