import java.io.*;
import java.util.*;

public class Main {

    static int[] sushi = new int[30001];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        HashMap<Integer, Integer> map = new HashMap<>();

        String input = br.readLine();

        StringTokenizer st = new StringTokenizer(input, " ");

        int N = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());


        for (int i = 0; i < N; i++) {
            int temp = Integer.parseInt(br.readLine());

            sushi[i] = temp;
        }

        map.put(c, 1);

        for (int i = 0; i < k; i++) {
            if (map.containsKey(sushi[i])) {
                map.put(sushi[i], map.get(sushi[i]) + 1);
            }
            else {
                map.put(sushi[i], 1);
            }
        }

        int ans = map.size();

        for (int i = k; i < N + k - 1; i++) {
            int val = map.get(sushi[(i - k) % N]);
            if (val - 1 == 0) {
                map.remove(sushi[(i - k) % N]);
            }
            else {
                map.put(sushi[(i - k) % N], val - 1);
            }
            if (map.containsKey(sushi[i % N])) {
                int val2 = map.get(sushi[i % N]);
                map.put(sushi[i % N], val2 + 1);
            }
            else {
                map.put(sushi[i % N], 1);
            }

            ans = Math.max(ans, map.size());
        }

        bw.write(String.valueOf(ans));
        bw.newLine();


        bw.flush();
    }
}