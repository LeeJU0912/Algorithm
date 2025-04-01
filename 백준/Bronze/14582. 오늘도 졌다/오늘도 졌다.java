import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] a = new int[9];
        int[] b = new int[9];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 9; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 9; i++) {
            b[i] = Integer.parseInt(st.nextToken());
        }

        int aHap = 0;
        int bHap = 0;
        boolean aWin = false;
        for (int i = 0; i < 9; i++) {
            aHap += a[i];
            if (aHap > bHap) aWin = true;
            
            bHap += b[i];
        }

        if (aWin) {
            bw.write("Yes");
        }
        else {
            bw.write("No");
        }

        bw.flush();
        bw.close();
    }
}