import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        String s = br.readLine();

        HashMap<String, String> map = new HashMap<>();
        map.put("000000", "A");
        map.put("001111", "B");
        map.put("010011", "C");
        map.put("011100", "D");
        map.put("100110", "E");
        map.put("101001", "F");
        map.put("110101", "G");
        map.put("111010", "H");

        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < N; i++) {
            String sub = s.substring(i * 6, (i + 1) * 6);

            boolean cant = true;

            for (String key : map.keySet()) {
                boolean flag = false;
                boolean not = false;
                for (int j = 0; j < 6; j++) {
                    if (sub.charAt(j) != key.charAt(j)) {
                        if (flag) {
                            not = true;
                            break;
                        }
                        flag = true;
                    }
                }

                if (!not) {
                    ans.append(map.get(key));
                    cant = false;
                }
            }

            if (cant) {
                bw.write(String.valueOf(i + 1));
                bw.flush();
                bw.close();
                return;
            }
        }

        bw.write(ans.toString());

        bw.flush();
        bw.close();
    }
}