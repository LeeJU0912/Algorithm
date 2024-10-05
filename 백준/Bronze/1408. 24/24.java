import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine(), ":");

        int[] a = new int[3];
        int[] b = new int[3];
        int[] c = new int[3];

        for (int i = 0; i < 3; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine(), ":");

        for (int i = 0; i < 3; i++) {
            b[i] = Integer.parseInt(st.nextToken());
        }


        if (b[2] < a[2]) {
            c[2] = 60 + b[2] - a[2];
            b[1]--;
            if (b[1] < 0) {
                b[1] += 60;
                b[0]--;
            }
        }
        else {
            c[2] = b[2] - a[2];
        }

        if (b[1] < a[1]) {
            c[1] = 60 + b[1] - a[1];
            b[0]--;
        }
        else {
            c[1] = b[1] - a[1];
        }
        if (b[0] < a[0]) {
            c[0] = 24 + b[0] - a[0];
        }
        else {
            c[0] = b[0] - a[0];
        }

        if (c[0] < 10) {
            bw.write("0" + c[0]);
        }
        else {
            bw.write(String.valueOf(c[0]));
        }
        for (int i = 1; i < 3; i++) {
            if (c[i] < 10) {
                bw.write(":0" + c[i]);
            }
            else {
                bw.write(":" + c[i]);
            }
        }

        bw.flush();
        bw.close();
    }
}