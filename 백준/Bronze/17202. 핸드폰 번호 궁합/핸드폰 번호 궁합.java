import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String a = br.readLine();
        String b = br.readLine();

        StringBuilder s = new StringBuilder();
        for (int i = 0; i < a.length(); i++) {
            s.append(a.charAt(i));
            s.append(b.charAt(i));
        }

        while(s.length() > 2) {
            StringBuilder next = new StringBuilder();

            for (int i = 0; i < s.length() - 1; i++) {
                int c = (s.charAt(i) - '0') + (s.charAt(i + 1) - '0');
                c %= 10;
                next.append(c);
            }

            s = next;
        }

        bw.write(s.toString());

        bw.flush();
        bw.close();
    }
}