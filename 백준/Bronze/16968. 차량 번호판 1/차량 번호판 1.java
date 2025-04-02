import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();

        if (s.isEmpty()) {
            bw.write("0");
            return;
        }

        int c = 1;
        int d = 1;
        int calcC = 1;
        int calcD = 1;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'c') {
                if (calcC != 1) {
                    calcC *= 25;
                }
                else {
                    calcC *= 26;
                }

                d *= calcD;
                calcD = 1;
            }
            else if (s.charAt(i) == 'd') {
                if (calcD != 1) {
                    calcD *= 9;
                }
                else {
                    calcD *= 10;
                }

                c *= calcC;
                calcC = 1;
            }
        }

        c *= calcC;
        d *= calcD;

        bw.write(String.valueOf(c * d));

        bw.flush();
        bw.close();
    }
}