import java.io.*;
import java.util.*;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        List<String> list = new ArrayList<>();

        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            String s = br.readLine();
            list.add(s);
        }

        list.sort(Comparator.comparingInt(String::length));

        int exclude = 0;
        for (int i = 0; i < N; i++) {
            String now = list.get(i);
            boolean isSame = false;

            for (int j = i + 1; j < N; j++) {
                String next = list.get(j);

                isSame = true;
                if (now.length() <= next.length()) {
                    for (int k = 0; k < now.length(); k++) {
                        if (now.charAt(k) != next.charAt(k)) {
                            isSame = false;
                            break;
                        }
                    }
                }
                else {
                    isSame = false;
                }

                if (isSame) {
                    break;
                }
            }

            if (isSame) {
                exclude++;
            }
        }

        bw.write(String.valueOf(N - exclude));

        bw.flush();
        bw.close();
    }
}