import java.io.*;
import java.util.*;

public class Main {
    static class INFO implements Comparable<INFO> {
        int len, l, r;

        INFO(int len, int l, int r) {
            this.len = len;
            this.l = l;
            this.r = r;
        }

        @Override
        public int compareTo(INFO o) {
            return this.len - o.len;
        }
    }

    static int N;
    static int[] parent = new int[51];
    static ArrayList<INFO> vertex = new ArrayList<>();

    static int connected;
    static int hap;
    static int ans;

    static int get_parent(int node) {
        if (parent[node] == node) return node;
        else return get_parent(parent[node]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            String s = br.readLine();

            parent[i] = i;

            for (int j = 0; j < N; j++) {
                if (s.charAt(j) >= 'a' && s.charAt(j) <= 'z') {
                    int len = s.charAt(j) - 'a' + 1;

                    hap += len;

                    if (i != j) {
                        INFO info = new INFO(len, i, j);
                        vertex.add(info);
                    }
                }
                else if (s.charAt(j) >= 'A' && s.charAt(j) <= 'Z') {
                    int len = s.charAt(j) - 'A' + 27;

                    hap += len;

                    if (i != j) {
                        INFO info = new INFO(len, i, j);
                        vertex.add(info);
                    }
                }
            }
        }

        Collections.sort(vertex);

        for (INFO now : vertex) {
            int l_parent = get_parent(now.l);
            int r_parent = get_parent(now.r);
            if (l_parent == r_parent) continue;

            parent[l_parent] = r_parent;
            ans += now.len;
            connected++;
        }

        if (connected == N - 1) {
            bw.write(String.valueOf(hap - ans));
        }
        else {
            bw.write("-1");
        }

        bw.flush();
        bw.close();
    }
}