import java.io.*;
import java.util.*;

public class Main {

    static int N, C;

    static int[] bag = new int[31];

    static int ans;

    static ArrayList<Long> left = new ArrayList<>();
    static ArrayList<Long> right = new ArrayList<>();

    static int upper_bound(int start, int end, long val) {
        while(start <= end) {
            int mid = (start + end) / 2;

            if (right.get(mid) <= val) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return start;
    }

    static void search_left(int idx, long hap) {
        if (idx == N / 2) {
            left.add(hap);
            return;
        }

        search_left(idx + 1, hap + bag[idx]);
        search_left(idx + 1, hap);
    }

    static void search_right(int idx, long hap) {
        if (idx == N) {
            right.add(hap);
            return;
        }

        search_right(idx + 1, hap + bag[idx]);
        search_right(idx + 1, hap);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            bag[i] = Integer.parseInt(st.nextToken());
        }

        search_left(0, 0);
        search_right(N / 2, 0);

        Collections.sort(right);

        for (int i = 0; i < left.size(); i++) {
            ans += upper_bound(0, right.size() - 1, C - left.get(i));
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}