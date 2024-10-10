import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();

        int a = 0;
        int b = 0;
        for (int i = 0; i < s.length() / 2; i++) {
            a += s.charAt(i) - '0';
            b += s.charAt(i + s.length() / 2) - '0';
        }

        if (a == b) {
            bw.write("LUCKY");
        }
        else {
            bw.write("READY");
        }
        
        bw.flush();
        bw.close();
    }
}