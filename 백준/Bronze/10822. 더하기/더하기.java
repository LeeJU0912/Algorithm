import java.io.*;
import java.util.StringTokenizer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine(), ",");

        int ans = 0;
        while(st.hasMoreTokens()) {
            ans += Integer.parseInt(st.nextToken());
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}