import java.io.*;
import java.util.*;

import static java.lang.Math.abs;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        int a_x, a_y;
        if (a % 4 == 0) {
            a_x = a / 4;
            a_y = 4;
        }
        else {
            a_x = a / 4 + 1;
            a_y = a % 4;
        }

        int b_x, b_y;
        if (b % 4 == 0) {
            b_x = b / 4;
            b_y = 4;
        }
        else {
            b_x = b / 4 + 1;
            b_y = b % 4;
        }

        bw.write(String.valueOf((b_x - a_x) + abs(b_y - a_y)));
        
        bw.flush();
        bw.close();
    }
}