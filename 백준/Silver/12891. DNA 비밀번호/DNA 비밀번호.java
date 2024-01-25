import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int S = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());

        String s = br.readLine();

        st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int G = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());

        if (A + C + G + T > P) {
            bw.write("0");
            bw.flush();
            return;
        }

        int count_A = 0, count_C = 0, count_G = 0, count_T = 0;
        int not_ans = 0;

        for (int i = 0; i < P; i++) {
            if (s.charAt(i) == 'A') count_A++;
            else if (s.charAt(i) == 'C') count_C++;
            else if (s.charAt(i) == 'G') count_G++;
            else if (s.charAt(i) == 'T') count_T++;
            else not_ans++;
        }

        int ans = 0;

        if (not_ans == 0 && count_A >= A && count_C >= C && count_G >= G && count_T >= T) ans++;

        for (int i = P; i < S; i++) {
            if (s.charAt(i - P) == 'A') count_A--;
            else if (s.charAt(i - P) == 'C') count_C--;
            else if (s.charAt(i - P) == 'G') count_G--;
            else if (s.charAt(i - P) == 'T') count_T--;
            else not_ans--;

            if (s.charAt(i) == 'A') count_A++;
            else if (s.charAt(i) == 'C') count_C++;
            else if (s.charAt(i) == 'G') count_G++;
            else if (s.charAt(i) == 'T') count_T++;
            else not_ans++;

            if (not_ans == 0 && count_A >= A && count_C >= C && count_G >= G && count_T >= T) ans++;
        }

        bw.write(String.valueOf(ans));

        bw.flush();
    }
}