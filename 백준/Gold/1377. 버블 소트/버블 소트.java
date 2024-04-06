import java.io.*;
import java.util.Arrays;

public class Main {
    static class INFO implements Comparable<INFO> {
        int value;
        int idx;

        @Override
        public int compareTo(INFO o) {
            return this.value - o.value;
        }
    }
    static INFO[] A = new INFO[500001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());

        for (int i = 1; i <= N; i++) {
            A[i] = new INFO();
            A[i].value = Integer.parseInt(br.readLine());
            A[i].idx = i;
        }

        Arrays.sort(A, 1, N + 1);

        int ans = -1;
        for (int i = 1; i <= N; i++) {
            if (ans < A[i].idx - i) {
                ans = A[i].idx - i;
            }
        }


        bw.write(String.valueOf(ans + 1));

        bw.flush();
        bw.close();
    }
}