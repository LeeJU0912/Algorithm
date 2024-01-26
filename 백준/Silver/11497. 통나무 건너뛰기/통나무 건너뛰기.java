import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        while(T --> 0) {
            int N = Integer.parseInt(br.readLine());

            int[] save = new int[N];

            StringTokenizer st = new StringTokenizer(br.readLine(), " ");

            for (int i = 0; i < N; i++) {
                save[i] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(save);

            Deque<Integer> dq = new ArrayDeque<>();

            for (int i = N - 1; i >= 0; i--) {
                if (i % 2 == 0) {
                    dq.addFirst(save[i]);
                }
                else {
                    dq.addLast(save[i]);
                }
            }

            int ans = Integer.MIN_VALUE;

            int first_value = dq.getFirst();
            while(true) {
                int one = dq.getFirst();
                dq.pollFirst();

                int two = dq.getFirst();

                ans = Math.max(ans, Math.abs(one - two));

                if (dq.size() == 1) {
                    ans = Math.max(ans, Math.abs(first_value - two));
                    break;
                }
            }

            bw.write(String.valueOf(ans));
            bw.newLine();
        }

        bw.flush();
    }
}