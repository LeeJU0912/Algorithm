import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        while(T != 0) {
            T--;

            int n = Integer.parseInt(br.readLine());

            boolean[] open = new boolean[n + 1];

            for (int i = 1; i <= n; i++) {
                for (int j = 1; i * j <= n; j++) {
                    open[i * j] = !open[i * j];
                }
            }

            int ans = 0;
            for (int i = 1; i <= n; i++) {
                if (open[i]) {
                    ans++;
                }
            }

            bw.write(ans + "\n");
        }

        bw.flush();
        bw.close();
    }
}