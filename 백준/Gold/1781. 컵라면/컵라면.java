import java.io.*;
import java.util.*;

public class Main {
    static class INFO implements Comparable<INFO> {
        int deadline;
        int ramen;

        public INFO(int deadline, int ramen) {
            this.deadline = deadline;
            this.ramen = ramen;
        }

        @Override
        public int compareTo(INFO o) {
            if (o.deadline == this.deadline) return this.ramen - o.ramen;
            else return this.deadline - o.deadline;
        }
    }

    static int N;
    static List<INFO> saved = new ArrayList<>();
    static PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

    static int ans;

    static void saving(int idx) {
        for (int i = idx; i >= 0; i--) {
            if (saved.get(idx).deadline != saved.get(i).deadline) return;
            pq.add(saved.get(i).ramen);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());

        saved.add(new INFO(0, 0));
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            saved.add(new INFO(a, b));
        }

        Collections.sort(saved);

        int now_time = saved.get(saved.size() - 1).deadline;

        saving(saved.size() - 1);

        int counter = now_time;

        for (int i = saved.size() - 1; i >= 0; i--) {
            if (saved.get(i).deadline < now_time) {
                now_time = saved.get(i).deadline;

                while(counter > now_time) {
                    if (pq.isEmpty()) break;
                    ans += pq.poll();
                    counter--;
                }

                saving(i);
                counter = Math.min(counter, now_time);
            }

            if (counter == 0) break;
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
    }
}