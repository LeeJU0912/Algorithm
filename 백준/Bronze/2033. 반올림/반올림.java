import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder s = new StringBuilder(br.readLine());
        boolean up = false;

        for (int i = s.length() - 1; i >= 1; i--) {
            if (up) {
                if (s.charAt(i) < '5') {
                    up = false;
                }
                else {
                    s.setCharAt(i - 1, (char) (s.charAt(i - 1) + 1));
                }
                s.setCharAt(i, '0');
            }
            else {
                if (s.charAt(i) >= '5') {
                    s.setCharAt(i - 1, (char) (s.charAt(i - 1) + 1));
                    up = true;
                }
                s.setCharAt(i, '0');
            }
        }

        if (s.charAt(0) > '9') {
            s.insert(0, s.charAt(0) - '9');
            s.setCharAt(1, '0');
        }

        bw.write(s.toString());

        bw.flush();
        bw.close();
    }
}