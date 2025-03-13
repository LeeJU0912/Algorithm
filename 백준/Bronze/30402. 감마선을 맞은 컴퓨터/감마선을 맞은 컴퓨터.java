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

        for (int i = 0; i < 15; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int j = 0; j < 15; j++) {
                String s = st.nextToken();
                if (s.equals("w")) {
                    bw.write("chunbae");
                    bw.flush();
                    bw.close();
                    return;
                }
                else if (s.equals("b")) {
                    bw.write("nabi");
                    bw.flush();
                    bw.close();
                    return;
                }
                else if (s.equals("g")) {
                    bw.write("yeongcheol");
                    bw.flush();
                    bw.close();
                    return;
                }
            }
        }

        //bw.flush();
        //bw.close();
    }
}