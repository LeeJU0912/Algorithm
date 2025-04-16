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

        int lastWin = 0;
        int cntA = 0;
        int cntB = 0;
        for (int i = 0; i < 10; i++) {
            if (A[i] == B[i]) {
                cntA++;
                cntB++;
            }
            else if (A[i] > B[i]) {
                cntA += 3;
                lastWin = 1;
            }
            else {
                cntB += 3;
                lastWin = 2;
            }
        }

        bw.write(cntA + " " + cntB);
        bw.newLine();
        if (cntA == cntB) {
            if (lastWin == 1) {
                bw.write("A");
            }
            else if (lastWin == 2) {
                bw.write("B");
            }
            else {
                bw.write("D");
            }
        }
        else if (cntA > cntB) {
            bw.write("A");
        }
        else {
            bw.write("B");
        }

        bw.flush();
        bw.close();
    }
}