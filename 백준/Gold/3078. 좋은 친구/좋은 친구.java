import java.io.*;
import java.util.*;


public class Main {
    static int N, K;
    static ArrayList<Integer>[] save = new ArrayList[21];

    static long ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        for (int i = 2; i <= 20; i++) {
            save[i] = new ArrayList<>();
        }

        for (int i = 0; i < N; i++) {
            String s = br.readLine();

            save[s.length()].add(i);
        }

        for (int i = 2; i <= 20; i++) {
            for (int j = 0; j < save[i].size(); j++) {
                int start = j;
                int end = save[i].size() - 1;

                if (start == end) break;

                int tmp = j;

                while(start <= end) {
                    int mid = (start + end) / 2;

                    if (save[i].get(mid) > save[i].get(j) + K) {
                        end = mid - 1;
                    }
                    else {
                        tmp = mid;
                        start = mid + 1;
                    }
                }

                ans += tmp - j;
            }
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}