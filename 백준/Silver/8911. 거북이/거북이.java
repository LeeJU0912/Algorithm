import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};

        int T = Integer.parseInt(br.readLine());
        while(T-- > 0) {
            int minX = 0;
            int maxX = 0;
            int minY = 0;
            int maxY = 0;
            String s = br.readLine();

            int nowX = 0, nowY = 0;
            int go = 0;
            for(int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (c == 'F') {
                    int nextX = nowX + dx[go];
                    int nextY = nowY + dy[go];
                    nowX = nextX;
                    nowY = nextY;

                    minX = min(minX, nowX);
                    maxX = max(maxX, nowX);
                    minY = min(minY, nowY);
                    maxY = max(maxY, nowY);
                }
                else if (c == 'B') {
                    int reverseGo = (go + 2) % 4;
                    int nextX = nowX + dx[reverseGo];
                    int nextY = nowY + dy[reverseGo];
                    nowX = nextX;
                    nowY = nextY;

                    minX = min(minX, nowX);
                    maxX = max(maxX, nowX);
                    minY = min(minY, nowY);
                    maxY = max(maxY, nowY);
                }
                else if (c == 'L') {
                    go = ((go - 1) + 4) % 4;
                }
                else if (c == 'R') {
                    go = (go + 1) % 4;
                }
            }

            bw.write(String.valueOf((maxX - minX) * (maxY - minY)));
            bw.newLine();
        }


        bw.flush();
        bw.close();
    }
}