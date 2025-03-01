import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        List<Integer> save = Collections.list(st).stream()
                .map(Object::toString)
                .map(Integer::parseInt)
                .collect(Collectors.toList());

        int sum = save.stream().reduce(0, Integer::sum);
        sum += (save.size() - 1) * 8;

        bw.write(sum / 24 + " " + sum % 24);

        bw.flush();
        bw.close();
    }
}