import java.io.*;
import java.util.*;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();

        boolean allA = true;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != 'a') {
                allA = false;
                break;
            }
        }
        if (allA) {
            bw.write("0");
            bw.flush();
            bw.close();
            return;
        }

        int ans = Integer.MAX_VALUE;
        for (int gap = s.length(); gap >= 1; gap--) {

            for (int start = 0; start < s.length(); start++) {
                int aCount = 0;
                int bOutside = 0;

                int add = 0;
                while (add < gap) {
                    if (s.charAt((start + add) % s.length()) == 'a') aCount++;
                    add++;
                }
                while ((start + add) % s.length() != start) {
                    if (s.charAt((start + add) % s.length()) == 'b') bOutside++;
                    add++;
                }
                
                if (aCount <= bOutside) {
                    ans = min(ans, bOutside);
                }
            }
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}