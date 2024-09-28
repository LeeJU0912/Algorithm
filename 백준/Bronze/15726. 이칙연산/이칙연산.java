import java.io.*;
import java.util.*;

import static java.lang.Math.max;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());

        double a = Integer.parseInt(st.nextToken());
        double b = Integer.parseInt(st.nextToken());
        double c = Integer.parseInt(st.nextToken());

        double ans = max(a * b / c, a / b * c);

        bw.write(String.valueOf((int) ans));

        bw.flush();
        bw.close();
    }
}