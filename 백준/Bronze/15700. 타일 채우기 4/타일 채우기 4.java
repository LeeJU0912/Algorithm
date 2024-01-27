import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());

        long N = Integer.parseInt(stringTokenizer.nextToken());
        long M = Integer.parseInt(stringTokenizer.nextToken());

        bw.write(String.valueOf(N * M / 2));

        bw.flush();
    }
}