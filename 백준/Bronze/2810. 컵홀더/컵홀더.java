import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        String s = br.readLine();

        boolean[] chk = new boolean[N + 1];

        for (int i = 0; i < N - 1; i++) {
            if (s.charAt(i) == 'L' && s.charAt(i + 1) == 'L') {
                chk[i] = true;
                chk[i + 2] = true;
                i++;
            }
        }

        for (int i = 0; i < N; i++) {
            if (s.charAt(i) == 'S') {
                if (!chk[i]) chk[i] = true;
                else chk[i + 1] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i <= N; i++) {
            if (chk[i]) ans++;
        }

        bw.write(String.valueOf(ans));
        
        bw.flush();
        bw.close();
    }
}