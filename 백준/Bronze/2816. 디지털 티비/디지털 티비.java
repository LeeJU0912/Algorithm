import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        List<String> channel = new ArrayList<>();
        boolean twoFirst = false;
        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            String s = br.readLine();
            channel.add(s);
            if (s.equals("KBS1") && channel.contains("KBS2")) {
                twoFirst = true;
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= 2; i++) {
            String toFind = "KBS" + i;
            for (int j = 0; j < N; j++) {
                if (channel.get(j).equals(toFind)) {
                    if (i == 2) {
                        if (twoFirst) {
                            for (int k = 1; k <= j + 1; k++) {
                                sb.append("1");
                            }
                            for (int k = 2; k <= j + 1; k++) {
                                sb.append("4");
                            }
                        }
                        else {
                            for (int k = 2; k <= j + 1; k++) {
                                sb.append("1");
                            }
                            for (int k = 2; k <= j; k++) {
                                sb.append("4");
                            }
                        }
                    }
                    else {
                        for (int k = 2; k <= j + 1; k++) {
                            sb.append("1");
                        }
                        for (int k = 2; k <= j + 1; k++) {
                            sb.append("4");
                        }
                    }

                    break;
                }
            }
        }

        bw.write(sb.toString());

        bw.flush();
        bw.close();
    }
}