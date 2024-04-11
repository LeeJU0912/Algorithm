import java.io.*;
import java.util.*;

public class Main {
    static class INFO implements Comparable<INFO> {
        int L, R;

        public INFO(int l, int r) {
            L = l;
            R = r;
        }

        public int compareTo(INFO o) {
            if (this.R == o.R) return this.L - o.L;
            else return this.R - o.R;
        }
    }
    static int N, M;
    static boolean[] borrow = new boolean[1001];
    static ArrayList<INFO> save = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        while(T-- > 0) {
            save.clear();

            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            for (int i = 1; i <= N; i++) {
                borrow[i] = false;
            }

            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());

                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                save.add(new INFO(a, b));
            }

            Collections.sort(save);

            int ans = 0;
            for (int i = 0; i < save.size(); i++) {
                for (int j = save.get(i).L; j <= save.get(i).R; j++) {
                    if (!borrow[j]) {
                        borrow[j] = true;
                        ans++;
                        break;
                    }
                }
            }

            bw.write(String.valueOf(ans));
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}