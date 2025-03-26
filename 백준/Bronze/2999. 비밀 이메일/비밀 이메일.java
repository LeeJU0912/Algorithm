import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();

        int R = 0;
        int C = 0;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = i; j <= s.length(); j++) {
                if (i * j == s.length()) {
                    if (i > R) {
                        R = i;
                        C = j;
                    }
                }
            }
        }

        char[][] save = new char[R][C];
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < R; j++) {
                save[j][i] = s.charAt(R * i + j);
            }
        }

        for (int i = 0; i < R; i++) {
            bw.write(save[i]);
        }

        bw.flush();
        bw.close();
    }
}