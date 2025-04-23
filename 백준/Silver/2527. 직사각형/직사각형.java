import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for (int i = 0; i < 4; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int[] a = new int[4];
            for (int j = 0; j < 4; j++) {
                a[j] = Integer.parseInt(st.nextToken());
            }

            int[] b = new int[4];
            for (int j = 0; j < 4; j++) {
                b[j] = Integer.parseInt(st.nextToken());
            }

            if (a[2] < b[0] || a[0] > b[2] || a[1] > b[3] || a[3] < b[1]) {
                bw.write("d");
            }
            else if (a[0] == b[2] || a[2] == b[0] || a[1] == b[3] || a[3] == b[1]) {
                if (a[0] == b[2] || a[2] == b[0]) {
                    if (a[1] > b[3] || a[3] < b[1]) {
                        bw.write("d");
                    }
                    else if (a[1] == b[3] || a[3] == b[1]) {
                        bw.write("c");
                    }
                    else {
                        bw.write("b");
                    }
                }
                else {
                    if (a[0] > b[2] || a[2] < b[0]) {
                        bw.write("d");
                    }
                    else {
                        bw.write("b");
                    }
                }
            }
            else if (a[0] < b[0] || a[2] > b[2] || a[1] < b[1] || a[3] > b[3]) {
                bw.write("a");
            }
            else if (b[0] < a[2] || b[2] > a[0] || b[1] < a[3] || b[3] > a[1]) {
                bw.write("a");
            }

            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}