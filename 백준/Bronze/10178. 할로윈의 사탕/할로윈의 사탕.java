import java.io.*;
import java.util.*;

public class Main {

    public static int c, v;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        while(T > 0) {
            T--;

            st = new StringTokenizer(br.readLine());
            c = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());

            bw.write("You get " + c / v + " piece(s) and your dad gets " + c % v + " piece(s).\n");
        }

        bw.flush();
        bw.close();
    }
}