import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int n = Integer.parseInt(br.readLine());

        int cnt = 1;
        int ans = 0;
        while (n != 0) {
            if (n - cnt < 0) cnt = 1;
            n -= cnt++;
            ans++;
        }

        bw.write(String.valueOf(ans));
        
        bw.flush();
        bw.close();
    }
}