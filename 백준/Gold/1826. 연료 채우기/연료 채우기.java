import java.io.*;
import java.util.*;

public class Main {
    static class INFO implements Comparable<INFO> {
        int dist;
        int fuel;

        public INFO(int dist, int fuel) {
            this.dist = dist;
            this.fuel = fuel;
        }

        @Override
        public int compareTo(INFO o) {
            return this.dist - o.dist;
        }
    }
    static int N, L, P;
    static LinkedList<INFO> station = new LinkedList<>();
    static PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;


        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            station.add(new INFO(a, b));
        }

        st = new StringTokenizer(br.readLine());
        L = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());

        Collections.sort(station);

        int ans = 0;

        while(P < L) {
            while(!station.isEmpty() && station.get(0).dist <= P) {
                pq.add(station.get(0).fuel);
                station.remove(0);
            }

            if (pq.isEmpty()) {
                ans = -1;
                break;
            }

            P += pq.poll();
            ans++;
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}