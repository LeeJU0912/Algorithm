import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();

        int x = Integer.parseInt(s);
        bw.write('가' + x - 1);

        bw.flush();
        bw.close();
    }
}