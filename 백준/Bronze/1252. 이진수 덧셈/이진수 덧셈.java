import java.io.*;
import java.util.StringTokenizer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        String a = st.nextToken();
        String b = st.nextToken();

        StringBuilder sb = new StringBuilder();
        int idxA = a.length() - 1;
        int idxB = b.length() - 1;
        boolean plus = false;
        while (idxA >= 0 || idxB >= 0) {
            if (idxA < 0) {
                int charB = b.charAt(idxB) - '0';
                if (plus) {
                    if (charB == 0) {
                        sb.append("1");
                        plus = false;
                    }
                    else {
                        sb.append("0");
                    }
                }
                else {
                    sb.append(charB);
                }

                idxB--;
            }
            else if (idxB < 0) {
                int charA = a.charAt(idxA) - '0';
                if (plus) {
                    if (charA == 0) {
                        sb.append("1");
                        plus = false;
                    }
                    else {
                        sb.append("0");
                    }
                }
                else {
                    sb.append(charA);
                }

                idxA--;
            }
            else {
                int charA = a.charAt(idxA) - '0';
                int charB = b.charAt(idxB) - '0';
                if (plus) {
                    if (charA + charB == 2) {
                        sb.append("1");
                    }
                    else if (charA + charB == 1) {
                        sb.append("0");
                    }
                    else if (charA + charB == 0) {
                        sb.append("1");
                        plus = false;
                    }
                }
                else {
                    if (charA + charB == 2) {
                        sb.append("0");
                        plus = true;
                    }
                    else if (charA + charB == 1) {
                        sb.append("1");
                    }
                    else if (charA + charB == 0) {
                        sb.append("0");
                    }
                }

                idxA--;
                idxB--;
            }
        }

        if (plus) {
            sb.append("1");
        }

        sb.reverse();

        while(sb.length() > 1 && sb.charAt(0) == '0')
            sb.deleteCharAt(0);

        bw.write(sb.toString());

        bw.flush();
        bw.close();
    }
}