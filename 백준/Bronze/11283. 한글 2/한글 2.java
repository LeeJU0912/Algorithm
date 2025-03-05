import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();

        int n = (s.charAt(0) - '가') + 1;

        bw.write(String.valueOf(n));

        bw.flush();
        bw.close();
    }
}