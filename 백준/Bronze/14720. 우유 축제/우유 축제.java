import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        int ans = 0;

        int turn = 0;
        for (int i = 0; i < N; i++) {
            int now = Integer.parseInt(st.nextToken());
            if (now == turn) {
                ans++;
                turn = (turn + 1) % 3;
            }
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}