import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        double score = 0;
        int allGrade = 0;

        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            st.nextToken();

            int cnt = Integer.parseInt(st.nextToken());
            String grade = st.nextToken();

            allGrade += cnt;

            switch (grade) {
                case "A+" -> score += (4.3 * cnt);
                case "A0" -> score += (4.0 * cnt);
                case "A-" -> score += (3.7 * cnt);
                case "B+" -> score += (3.3 * cnt);
                case "B0" -> score += (3.0 * cnt);
                case "B-" -> score += (2.7 * cnt);
                case "C+" -> score += (2.3 * cnt);
                case "C0" -> score += (2.0 * cnt);
                case "C-" -> score += (1.7 * cnt);
                case "D+" -> score += (1.3 * cnt);
                case "D0" -> score += (1.0 * cnt);
                case "D-" -> score += (0.7 * cnt);
            }
        }

        bw.write(String.format("%.2f", score / allGrade));

        bw.flush();
        bw.close();
    }
}