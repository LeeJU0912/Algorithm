import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] cnt = new int[3];
        int[][] cnt2 = new int[3][4];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            cnt[0] += a;
            cnt[1] += b;
            cnt[2] += c;

            cnt2[0][a]++;
            cnt2[1][b]++;
            cnt2[2][c]++;
        }

        int ans = -1;
        int maxi = 0;
        boolean cant = false;

        for (int i = 0; i < 3; i++) {
            if (cnt[i] > maxi) {
                ans = i;
                maxi = cnt[i];
                cant = false;
            }
            else if (cnt[i] == maxi) {
                if (cnt2[ans][3] < cnt2[i][3]) {
                    ans = i;
                    cant = false;
                }
                else if (cnt2[ans][3] == cnt2[i][3]) {
                    if (cnt2[ans][2] < cnt2[i][2]) {
                        ans = i;
                        cant = false;
                    }
                    else if (cnt2[ans][2] == cnt2[i][2]) {
                        cant = true;
                    }
                }
            }
        }

        if (cant) {
            bw.write(0 + " " + maxi);
        }
        else {
            bw.write((ans + 1) + " " + maxi);
        }

        bw.flush();
        bw.close();
    }
}