import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.IntStream;

import static java.lang.Math.*;

public class Main {

    static class Point {
        int x, y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        List<Point> points = new ArrayList<>();

        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            points.add(new Point(a, b));
        }

        List<Point> gap = new ArrayList<>();

        int startIdx = 0;
        int minX = Integer.MAX_VALUE;
        int minY = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            if (minX > points.get(i).x) {
                startIdx = i;
                minX = points.get(i).x;
                minY = points.get(i).y;
            }
            else if (minX == points.get(i).x) {
                if (minY > points.get(i).y) {
                    startIdx = i;
                    minY = points.get(i).y;
                }
            }
        }
        
        Point start = null;
        for (int i = startIdx; i < N; i++) {
            int b = points.get(i).y;

            int c, d;
            if (i == N - 1) {
                c = points.get(0).x;
                d = points.get(0).y;
            }
            else {
                c = points.get(i + 1).x;
                d = points.get(i + 1).y;
            }

            if (b < 0 && d < 0) {
                continue;
            }

            if (b < 0 && d > 0) {
                start = new Point(c, d);
            }
            else if (b > 0 && d < 0) {
                if (start != null) {
                    gap.add(new Point(min(start.x, c), max(start.x, c)));
                    start = null;
                }
            }
        }

        for (int i = 0; i < startIdx - 1; i++) {
            int b = points.get(i).y;

            int c, d;
            if (i == N - 1) {
                c = points.get(0).x;
                d = points.get(0).y;
            }
            else {
                c = points.get(i + 1).x;
                d = points.get(i + 1).y;
            }

            if (b < 0 && d < 0) {
                continue;
            }

            if (b < 0 && d > 0) {
                start = new Point(c, d);
            }
            else if (b > 0 && d < 0) {
                if (start != null) {
                    gap.add(new Point(min(start.x, c), max(start.x, c)));
                    start = null;
                }
            }
        }

        gap.sort((p1, p2) -> {
            if (p1.x == p2.x) {
                return p2.y - p1.y;
            }
            return p1.x - p2.x;
        });
        
        int ans1 = 1;

        if (!gap.isEmpty()) {
            Point nowMax = gap.get(0);
            for (int i = 1; i < gap.size(); i++) {
                if (nowMax.y < gap.get(i).x) {
                    ans1++;
                    nowMax = gap.get(i);
                }
            }
        }

        int ans2 = 1;
        for (int i = 0; i < gap.size() - 1; i++) {
            if (gap.get(i).y < gap.get(i + 1).x) {
                ans2++;
            }
        }

        bw.write(ans1 + " " + ans2);

        bw.flush();
        bw.close();
    }
}