import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        ArrayList<Integer> a = new ArrayList<>();
        ArrayList<Integer> b = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            int x = Integer.parseInt(br.readLine());
            a.add(x);
        }

        for (int i = 0; i < 10; i++) {
            int x = Integer.parseInt(br.readLine());
            b.add(x);
        }

        a.sort(Collections.reverseOrder());
        b.sort(Collections.reverseOrder());

        int aSum = 0;
        int bSum = 0;
        for (int i = 0; i < 3; i++) {
            aSum += a.get(i);
            bSum += b.get(i);
        }

        bw.write(aSum + " " + bSum);
        
        bw.flush();
        bw.close();
    }
}