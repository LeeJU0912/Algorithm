import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

import static java.lang.Math.min;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int bornYear = Integer.parseInt(st.nextToken());
        int bornMonth = Integer.parseInt(st.nextToken());
        int bornDay = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int nowYear = Integer.parseInt(st.nextToken());
        int nowMonth = Integer.parseInt(st.nextToken());
        int nowDay = Integer.parseInt(st.nextToken());

        int yearGap = nowYear - bornYear - 1;
        int monthGap = nowMonth - bornMonth;
        int dayGap = nowDay - bornDay;

        if (monthGap == 0) {
            if (dayGap >= 0) {
                yearGap++;
            }
        }
        else if (monthGap > 0) {
            yearGap++;
        }

        bw.write(yearGap + "\n" + (nowYear - bornYear + 1) + '\n' + (nowYear - bornYear));

        bw.flush();
        bw.close();
    }
}