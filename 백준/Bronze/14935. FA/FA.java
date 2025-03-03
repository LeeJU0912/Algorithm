import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();

        int length = s.length();
        int x = (s.charAt(0) - '0') * length;

        boolean found;

        while(true) {
            String nowX = String.valueOf(x);
            int calcLen = nowX.length();
            int calcX = (nowX.charAt(0) - '0') * calcLen;

            if (calcX == x && calcLen == length) {
                found = true;
                break;
            }

            x = calcX;
            length = calcLen;
        }

        if (found) {
            bw.write("FA");
        }
        else {
            bw.write("NFA");
        }

        bw.flush();
        bw.close();
    }
}