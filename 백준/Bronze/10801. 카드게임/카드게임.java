import java.io.*;
import java.util.StringTokenizer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] A = new int[10];
        int[] B = new int[10];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 10; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 10; i++) {
            B[i] = Integer.parseInt(st.nextToken());
        }

        int scoreA = 0;
        int scoreB = 0;
        for (int i = 0; i < 10; i++) {
            if (A[i] > B[i]) {
                scoreA++;
            }
            else if (B[i] > A[i]) {
                scoreB++;
            }
        }

        if (scoreA > scoreB) {
            bw.write("A");
        }
        else if (scoreB > scoreA) {
            bw.write("B");
        }
        else {
            bw.write("D");
        }

        bw.flush();
        bw.close();
    }
}