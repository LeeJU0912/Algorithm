import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        String a = st.nextToken();
        String b = st.nextToken();

        for (int i = 0; i < a.length(); i++) {
            for (int j = 0; j < b.length(); j++) {
                if (a.charAt(i) == b.charAt(j)) {
                    for (int k = 0; k < b.length(); k++) {
                        for (int l = 0; l < a.length(); l++) {
                            if (k == j) {
                                bw.write(a.charAt(l));
                            }
                            else {
                                if (l == i) {
                                    bw.write(b.charAt(k));
                                }
                                else {
                                    bw.write(".");
                                }
                            }
                        }
                        bw.newLine();
                    }
                    bw.flush();
                    bw.close();
                    return;
                }
            }
        }

        bw.flush();
        bw.close();
    }
}